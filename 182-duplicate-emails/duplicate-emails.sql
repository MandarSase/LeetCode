SELECT distinct t1.email
FROM Person as t1, Person as t2
where t1.email=t2.email
and t1.id <> t2.id
;