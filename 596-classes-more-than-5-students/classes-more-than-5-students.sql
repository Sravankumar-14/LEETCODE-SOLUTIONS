# Write your MySQL query statement bel
select class from Courses group by class having count(class) >= 5;