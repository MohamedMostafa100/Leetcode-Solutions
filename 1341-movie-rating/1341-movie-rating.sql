# Write your MySQL query statement below
WITH TopUser AS (SELECT name AS Results
FROM MovieRating R, Users U
WHERE R.user_id = U.user_id
GROUP BY R.user_id
ORDER BY COUNT(*) DESC, name ASC
LIMIT 1),
TopMovie AS (SELECT title AS results
FROM MovieRating R, Movies M
WHERE R.movie_id = M.movie_id AND MONTH(R.created_at) = 2 AND YEAR(R.created_at) = '2020'
GROUP BY R.movie_id
ORDER BY AVG(R.rating) DESC, title ASC
LIMIT 1)

SELECT results FROM TopUser
UNION ALL
SELECT results FROM TopMovie
