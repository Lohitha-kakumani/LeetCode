# Write your MySQL query statement below
select e.name as Employee
from Employee e
join Employee em
on e.managerId = em.id
where e.salary > em.salary;