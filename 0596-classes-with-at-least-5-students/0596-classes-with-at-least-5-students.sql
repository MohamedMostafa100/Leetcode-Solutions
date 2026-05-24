/* Write your T-SQL query statement below */
SELECT class
FROM (SELECT class, COUNT(*) AS #_of_Stdents
FROM Courses
GROUP BY class) AS classes
WHERE #_of_Stdents >= 5;
