# Write your MySQL query statement below
select r.contest_id,
ROUND((count(DISTINCT r.user_id)/(select count(*) from Users))*100,2) as percentage 
from Register r
group by r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;