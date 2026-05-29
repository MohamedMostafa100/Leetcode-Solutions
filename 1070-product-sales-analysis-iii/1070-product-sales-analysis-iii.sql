/* Write your T-SQL query statement below */

SELECT S.product_id, S.year as first_year, S.quantity, S.price
FROM Sales S
WHERE S.year IN (SELECT MIN(year) FROM Sales S1 WHERE S.product_id = S1.product_id)