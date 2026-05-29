/* Write your T-SQL query statement below */
with CTE AS

(

   
   select d.name as Department , e.name as employee , salary , dense_rank() over (PARTITION by d.name order by salary desc ) as rn From employee e join Department d on e.departmentid = d.id 
     

)
select Department , employee , salary From CTE where rn = 1
