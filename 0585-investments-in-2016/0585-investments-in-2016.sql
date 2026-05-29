/* Write your T-SQL query statement below */
SELECT ROUND(SUM(CAST(tiv_2016 AS NUMERIC(18,2))), 2) AS tiv_2016
FROM insurance i
WHERE tiv_2015 IN (
    SELECT tiv_2015 FROM insurance
    GROUP BY tiv_2015
    HAVING COUNT(pid) > 1
) AND EXISTS (
    SELECT 1 FROM insurance sub
    WHERE sub.lat = i.lat AND sub.lon = i.lon
    GROUP BY lat, lon
    HAVING COUNT(pid) = 1
);