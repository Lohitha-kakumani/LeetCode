# Write your MySQL query statement below
WITH first_scores as (
SELECT student_id, subject, score, exam_date, row_number() over(partition by student_id, subject order by exam_date) as first_test from scores
),
latest_scores as (
    SELECT student_id, subject, score, exam_date, row_number() over(partition by student_id, subject order by exam_date desc) as last_test from scores
)
SELECT a.student_id, a.subject, a.score as first_score, b.score as latest_score
FROM first_scores a LEFT JOIN latest_scores b on a.student_id = b.student_id and a.subject = b.subject and a.exam_date < b.exam_date
where first_test = 1 and last_test = 1 and a.score < b.score
order by student_id, subject