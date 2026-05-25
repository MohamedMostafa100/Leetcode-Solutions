# Write your MySQL query statement below
SELECT C.customer_id
FROM (SELECT COUNT(*) AS products_count FROM Product) AS P, (SELECT customer_id, COUNT(DISTINCT product_key) AS products_pur
FROM Customer
GROUP BY customer_id) AS C
WHERE C.products_pur = P.products_count;
