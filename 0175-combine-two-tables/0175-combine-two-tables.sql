# Write your MySQL query statement below
select p.firstname,p.lastName,a.city,a.state
from  Person p
left join Address a
on p.personId = a.personId
group by p.personId