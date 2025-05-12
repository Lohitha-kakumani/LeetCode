# Write your MySQL query statement below
Select 'Low Salary' as category, count(*) as accounts_count
from Accounts
where income < 20000
union
Select 'Average Salary' as category, count(*) as accounts_count
from Accounts
where income >= 20000 and income <= 50000
union
Select 'High Salary' as category, count(*) as accounts_count
from Accounts
where income > 50000