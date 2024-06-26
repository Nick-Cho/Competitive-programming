from functools import cache
import sys

sys.setrecursionlimit(10**9)
# Define the rules
rules = [
    {'points': 500, 'requirements': {'sportcheck': 75, 'tim_hortons': 25, 'subway': 25}},
    {'points': 300, 'requirements': {'sportcheck': 75, 'tim_hortons': 25}},
    # {'points': 200, 'requirements': {'sportcheck': 75}}, -- never better than the alternative of 75 points for 20 dollars
    {'points': 150, 'requirements': {'sportcheck': 25, 'tim_hortons': 10, 'subway': 10}},
    # {'points': 75, 'requirements': {'sportcheck': 25, 'tim_hortons': 10}},
    {'points': 75, 'requirements': {'sportcheck': 20}},
    {'points': 1, 'requirements': {}}
]


def calculate_reward_points(transactions, tx_level_points):
    merchant_spent = [0, 0, 0] # index: 0 - sportcheck, 1 - tim_hortons, 2 - subway
    name_to_idx = {"sportcheck": 0, "tim_hortons": 1, "subway": 2}
    i = 0
    
    for tx in transactions.keys():
        merchant_name = transactions[tx]["merchant"]
        
        if merchant_spent[name_to_idx[merchant_name]] < 0:
            raise ValueError("Transaction amount cannot be negative")
        
        if merchant_name in name_to_idx:
            merchant_spent[name_to_idx[merchant_name]] += transactions[tx]["amount"] // 100
        else:
            name_to_idx[merchant_name] = len(merchant_spent)
            merchant_spent.append(transactions[tx]["amount"] // 100)
        
        if merchant_name == "sportcheck":
            tx_level_points[i] = ((transactions[tx]["amount"] // 100) // 20) * 75
            leftover = (transactions[tx]["amount"]//100) % 20
            tx_level_points[i] = tx_level_points[i] + (leftover) 
        else:
            # no rules for other merchants when isolated other than basic 1 point for every dollar spent
            tx_level_points[i] = transactions[tx]["amount"] // 100 
        i+=1
            
    max_points = 0

    for i, rule in enumerate(rules):    
        b_can_apply_rule = True
        max_applications = max(merchant_spent) 
        if i == len(rules)-1:
            max_points += sum(merchant_spent)
            
        else:    
            for merchant, idx in name_to_idx.items():
                if merchant in rule["requirements"]:
                    max_applications = min(max_applications, merchant_spent[idx] // rule["requirements"][merchant])
                    if merchant_spent[idx] < rule["requirements"][merchant]:
                        b_can_apply_rule = False
                        break
            
            if b_can_apply_rule:
                points = rule["points"] * max_applications
                for merchant, idx in name_to_idx.items():
                    merchant_spent[idx] -= max_applications * rule["requirements"].get(merchant, 0)
                max_points += points

    return max_points
    
# Example usage with sample transactions
# transactions = {
#     "T01": {"date": "2021-05-01", "merchant": "sportcheck", "amount": 21000},
#     "T02": {"date": "2021-05-02", "merchant": "sportcheck", "amount": 8700},
#     "T03": {"date": "2021-05-03", "merchant": "tim_hortons", "amount": 323},
#     "T04": {"date": "2021-05-04", "merchant": "tim_hortons", "amount": 1267},
#     "T05": {"date": "2021-05-05", "merchant": "tim_hortons", "amount": 2116},
#     "T06": {"date": "2021-05-06", "merchant": "tim_hortons", "amount": 2211},
#     "T07": {"date": "2021-05-07", "merchant": "subway", "amount": 1853},
#     "T08": {"date": "2021-05-08", "merchant": "subway", "amount": 2153},
#     "T09": {"date": "2021-05-09", "merchant": "sportcheck", "amount": 7326},
#     "T10": {"date": "2021-05-10", "merchant": "tim_hortons", "amount": 1321}
# }

transactions = {}
# Assumes input comes from a file with a structure of: Merchant Name -> Amount
# e.g. sportcheck -> 21000
with open('./input.txt', 'r') as file:
    tx_id = 1
    for line in file:
        merchant, amount = line.strip().split('->')
        if tx_id < 10:
            transactions[f"T0{tx_id}"] = {"merchant": merchant.strip(), "amount": int(amount.strip())}
        else:
            transactions[f"T{tx_id}"] = {"merchant": merchant.strip(), "amount": int(amount.strip())}
        tx_id += 1
        
tx_level_points = [0] * len(transactions)
result = calculate_reward_points(transactions, tx_level_points)
print("Total Points:", result)
print("Transaction Level Points:")
for tx_id, points in enumerate(tx_level_points):
    if tx_id < 9:
        print(f"T0{tx_id+1}: {points}")
    else:
        print(f"T{tx_id+1}: {points}")
