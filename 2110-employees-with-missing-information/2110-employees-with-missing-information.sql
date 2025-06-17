select employee_id
from (
    select e.employee_id, e.name, s.salary
    from employees e
    left join salaries s on e.employee_id = s.employee_id
    union
    select s.employee_id, e.name, s.salary
    from salaries s
    left join employees e on e.employee_id = s.employee_id
) as combined
where name is null or salary is null
order by employee_id;
