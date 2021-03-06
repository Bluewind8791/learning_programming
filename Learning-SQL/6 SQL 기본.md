# ๐ SELECT ๋ฌธ

## SELECT...FROM

์ํ๋ ๋ฐ์ดํฐ๋ฅผ ๊ฐ์ ธ์์ฃผ๋ ๊ธฐ๋ณธ์ ์ธ ๊ตฌ๋ฌธ

```sql
SELECT {column}
FROM {table}
WHERE {where_condition}
GROUP BY {col_name | expression | position} # ๋ฌด์์ ๊ธฐ์ค์ผ๋ก ํด์ ํ๊ท ์ด๋ ํฉ๊ณ ์ต๋๊ฐ ๋ฑ์ ๊ตฌํ ๋
HAVING {where_condition} 
ORDER BY {col_name | expression | position} # ์ ๋ ฌ
```
```sql
SELECT {์ด ์ด๋ฆ}
FROM {ํ์ด๋ธ ์ด๋ฆ}
WHERE {์กฐ๊ฑด}
```

์ ํ๋ DB๊ฐ `employees`๋ผ๋ฉด ๋ค์ ๋ ์ฟผ๋ฆฌ๋ ๋์ผํจ.

```sql
SELECT * FROM employees; # ํ์ด๋ธ์ ๋ชจ๋  ํ ์ ํ ๋ฐ ์ง์
SELECT * FROM employees.employees; # DB์์ Table ์ ํ ๋ฐ ์ง์
```


`employees` ํ์ด๋ธ ์์ ํน์  column ์ `SELECT`

```sql
SELECT last_name, first_name FROM employees;
```

- Column์ ์ด๋ฆ์ ๋ณ๊ฒฝํ์ฌ ์ถ๋ ฅ
- `AS`๋ ์๋ต์ด ๊ฐ๋ฅ
- ""๋ ์๋ต์ด ๊ฐ๋ฅํ๋ ์ค๊ฐ์ ๊ณต๋ฐฑ์ด์์ผ๋ฉด ์๋ต ๋ถ๊ฐ.

```sql
SELECT last_name AS "์ฑ", first_name AS "์ด๋ฆ" FROM employees;
SELECT last_name "์ฑ", first_name "์ด๋ฆ" FROM employees;
```



## SELECT...FROM...WHERE

### ๊ธฐ๋ณธ์ ์ธ WHERE ์ 

์กฐ๊ฑด์ ๋ถํฉํ๋ ๋์์ `SELECT` ํฉ๋๋ค.

```sql
SELECT * FROM usertbl WHERE name='๊น๊ฒฝํธ'; -- ์ ํํ ์กฐ๊ฑด
```


### ๊ด๊ณ ์ฐ์ฐ์์ ์ฌ์ฉ

- `OR` ์ฐ์ฐ์
- `AND` ์ฐ์ฐ์
- ์กฐ๊ฑด ์ฐ์ฐ์ (`=`, `<`, `>`, `<=`, `>=`, `!=` ๋ฑ)
- ๊ด๊ณ ์ฐ์ฐ์ (`NOT`, `AND`, `OR` ๋ฑ)


### BETWEEN...AND 

๋ฐ์ดํฐ๊ฐ ์ซ์๋ก ๊ตฌ์ฑ๋์ด ์์ผ๋ฉฐ ์ฐ์์ ์ธ ๊ฐ

```sql
SELECT * FROM usertbl WHERE height BETWEEN 180 AND 190;
```

### IN(...)

์ด์ฐ์ ์ธ ๊ฐ์ ์กฐ๊ฑด

```sql
SELECT * FROM usertbl WHERE addr IN ('์์ธ', '๊ฒฝ๊ธฐ');
```


### LIKE

๋ฌธ์์ด์ ๋ด์ฉ ๋ถ๋ถ๋ณ ์กฐ๊ฑด ๊ฒ์

```sql
SELECT * FROM usertbl WHERE name LIKE '%๊ฒฝํธ';
SELECT * FROM usertbl WHERE name LIKE '%๊ฒฝ%';
SELECT * FROM usertbl WHERE name LIKE '_๊ฒฝํธ';
```

## ANY/ALL/SOME/์๋ธ์ฟผ๋ฆฌ


### ์๋ธ ์ฟผ๋ฆฌ (SubQuery, ํ์์ฟผ๋ฆฌ)

์ฟผ๋ฆฌ๋ฌธ ์์ ๋ ์ฟผ๋ฆฌ๋ฌธ์ด ์๋ ๊ฒ

```SQL
SELECT height FROM usertbl WHERE name = '๊น๊ฒฝํธ'; -- ์ด๋ฆ์ด ๊น๊ฒฝํธ์ด๋ฉฐ
SELECT * FROM usertbl WHERE height >= 177; -- ํค๊ฐ 177 ์ด์์ธ ์ฌ๋

-- ์์ ๋ ์กฐ๊ฑด์ ์๋ธ์ฟผ๋ฆฌ๋ก ํฉ์น ๊ฒฐ๊ณผ
SELECT * FROM usertbl
WHERE height >= (SELECT height FROM usertbl WHERE name ='๊น๊ฒฝํธ');
```


### ANY
  - ์๋ธ์ฟผ๋ฆฌ์ ์ฌ๋ฌ ๊ฒฐ๊ณผ ์ค ํ๊ฐ์ง๋ง ๋ง์กฑํด๋ ๊ฐ๋ฅ
  - `SOME`์ `ANY`์ ๋์ผํ ์๋ฏธ๋ก ์ฌ์ฉ
  - `= ANY(์๋ธ์ฟผ๋ฆฌ)`๋ `IN(์๋ธ์ฟผ๋ฆฌ)`์ ๋์ผํ ์๋ฏธ


### ALL
  - ์๋ธ์ฟผ๋ฆฌ์ ๊ฒฐ๊ณผ ์ค ์ฌ๋ฌ ๊ฐ์ ๊ฒฐ๊ณผ๋ฅผ ๋ชจ๋ ๋ง์กฑํด์ผ ํจ.

- `> ANY` : ์ต์๊ฐ ๋ณด๋ค ํฐ
- `> ALL` : ์ต๋๊ฐ ๋ณด๋ค ํฐ
- `< ANY` : ์ต๋๊ฐ ๋ณด๋ค ์์
- `< ALL` : ์ต์๊ฐ ๋ณด๋ค ์์

```sql
-- ์์ธ์ธ ์ฌ๋๋ค์ด ๋ค์์์ผ๋ก ANY ์ฌ์ฉํด์ผํจ
SELECT * FROM usertbl WHERE height >=ANY (SELECT height FROM usertbl WHERE addr='์์ธ');
```

## ์ํ๋ ์์๋๋ก ์ ๋ ฌ

### ORDER BY ์ 

- ์ํ๋ ์์๋๋ก ์ ๋ ฌํ์ฌ ์ถ๋ ฅ
- default ๊ฐ์ ์ค๋ฆ์ฐจ์ (`ASC`)
- ๋ด๋ฆผ์ฐจ์์ผ๋ก ์ ๋ ฌํ๊ธฐ ์ํด์๋ `DESC`๋ฅผ ์ฌ์ฉ

```sql
-- height๋ฅผ ๊ธฐ์ค์ผ๋ก ์ค๋ฆ์ฐจ์ ์ ๋ ฌ
SELECT * FROM usertbl ORDER BY height;

-- Column ์ ๋ฒํธ(์์)๋ฅผ ์ ์ด์ ์ ๋ ฌํ  ์ ์๋ค.
SELECT * FROM usertbl ORDER BY 7;

-- `ORDER BY` ๊ตฌ๋ฌธ์ ํผํฉํ์ฌ ์ฌ์ฉ
SELECT name, height FROM usertbl ORDER BY height DESC, name ASC;
```


### DISTINCT

- ์ค๋ณต๋ ๊ฒ์ ๊ณจ๋ผ์ ์ธ๊ธฐ ์ด๋ ค์ธ ๋ ์ฌ์ฉํ๋ ๊ตฌ๋ฌธ
- ์ค๋ณต๋ ๊ฒ์ 1๊ฐ๋ง ๋ณด์ฌ์ฃผ๋ฉด์ ์ถ๋ ฅ
- ํ์ด๋ธ์ ํฌ๊ธฐ๊ฐ ํด์๋ก ํจ์จ์ 


```sql
-- addr, mobile1 ์ผ๋ก ์ค๋ณต์ ํํ์ฌ DISTINCT ํ๋ฉด ์๋ฏธ ์๋ค.
SELECT DISTINCT addr FROM usertbl;
```


### LIMIT

- ์ถ๋ ฅํ๋ ๊ฐ์๋ฅผ ์ ํํ๋ ๊ตฌ๋ฌธ
- ์ ์ฒด์์ ์์ n ๊ฐ๋ง ์ถ๋ ฅ

```sql
SELECT * FROM usertbl LIMIT 3;

-- 3๋ฒ๋ถํฐ 5๊ฐ์ ๋ฐ์ดํฐ๋ฅผ ์ถ๋ ฅ (4,5,6,7,8)
SELECT * FROM usertbl LIMIT 3, 5;
```




## GROUP BY ๋ฐ HAVING ๊ทธ๋ฆฌ๊ณ  ์ง๊ณ ํจ์


### GROUP BY ์ 

- ๊ทธ๋ฃน์ผ๋ก ๋ฌถ์ด์ฃผ๋ ์ญํ 
- ์ง๊ณ ํจ์์ ํจ๊ป ์ฌ์ฉ

```sql
SELECT userid, SUM(amount) FROM buytbl GROUP BY userID;
```

`GROUP BY`์ ์์ฃผ ์ฌ์ฉ๋๋ ์ง๊ณํจ์๋ฅผ ํฌํจ

```sql
SELECT name, height
FROM usertbl 
WHERE 
	height=(SELECT MAX(height) FROM usertbl)
	or
	height=(SELECT MIN(height) FROM usertbl)
;
```

### ์ง๊ณ ํจ์ (ํต๊ณ ํจ์)

ํจ์๋ช | ์ค๋ช |
-|-|
SUM() | ํฉ๊ณ
AVG() | ํ๊ท 
MIN() | ์ต์๊ฐ
MAX() | ์ต๋๊ฐ
COUNT()	| ๊ฐ์๋ฅผ ์นด์ดํธ
COUNT(DISTINCT)	| ๊ฐ์ ์นด์ดํธ (์ค๋ณต์ 1๊ฐ๋ง ์ธ์ )
STDEV()	| ํ์คํธ์ฐจ
VAR_SAMP() | ๋ถ์ฐ


```sql
-- ์ ์ฒด ๊ตฌ๋งค์๊ฐ ๊ตฌ๋งคํ ๋ฌผํ์ ๊ฐ์ ํ๊ท 
SELECT AVG(amount) AS "๊ตฌ๋งคํ ์๋ ํ๊ท " FROM buytbl;
```



### HAVING

- `WHERE`๊ณผ ๋น์ทํ ๊ฐ๋์ด์ง๋ง **์ง๊ณ ํจ์์ ๋ํด์ ํํฐ๋ง**์ ํ๋ ๊ฒ
- `GROUP BY` ์์๋ `WHERE`์ ์ธ ์ ์์ผ๋ฉฐ `HAVING`์ ์ฌ์ฉํด์ผ ํ๋ค.
- `HAVING`์ ์ ๋ฐ๋์ `GROUP BY`์  ๋ค์์ ๋์์ผ ํ๋ค.

```sql
SELECT userid, SUM(amount*price) AS "์ด ๊ตฌ๋งค์ก"
FROM buytbl
GROUP BY userid
HAVING SUM(price*amount) >= 1000;
```



### ROLLUP

- ์ค๊ฐ ํฉ๊ณ (์๊ณ) ๊ฐ ํ์ํ ๋ ์ฌ์ฉ
- `GROUP BY`์ ๊ณผ ํจ๊ป `WITH ROLLUP`๋ฌธ ์ฌ์ฉ

```sql
SELECT num, groupName, SUM(price*amount) AS 'Cost'
FROM buytbl
GROUP BY groupName, num
WITH ROLLUP;
```





## SQL์ ๋ถ๋ฅ

- DML (Data Manipuation Language : ๋ฐ์ดํฐ ์กฐ์ ์ธ์ด)
  - ๋ฐ์ดํฐ๋ฅผ ๋ค๋ฃจ๋ ์ธ์ด
  - `SELECT`, `INSERT`, `UPDATE`, `DELETE` ๊ตฌ๋ฌธ์ด ํด๋น
  - ํธ๋์ญ์์ด ๋ฐ์ํ๋ SQL๋ ํฌํจ (์์๋ก ์ ์ฉ ์ํค๋๊ฒ, ์ทจ์ ๊ฐ๋ฅํ ๊ฒ)

- DDL (Data Definition Language: ๋ฐ์ดํฐ ์ ์ ์ธ์ด)
  - `CREATE`, `DROP`, `ALTER` ์์ฃผ ์ฌ์ฉ
  - DDL์ ํธ๋์ ์ ๋ฐ์X (์ทจ์ ๋ถ๊ฐ)

- DCL (Data Control Language: ๋ฐ์ดํฐ ์ ์ด ์ธ์ด)
  - ์ฌ์ฉ์์๊ฒ ๊ถํ์ ๋ถ์ฌํ๋ ์ธ์ด
  - `GRANT`(๊ถํ ๋ถ์ฌ), `REVOKE`(๊ถํ ํ์), `DENY`



# ๐ ๋ฐ์ดํฐ์ ๋ณ๊ฒฝ


## INSERT

```SQL
INSERT [INTO] ํ์ด๋ธ[(colum1, column2, ...)] VALUES (value1, value2 ... )

-- ๊ฐ์ฅ ์ผ๋ฐ์ ์ธ ํ์
INSERT INTO testtbl1 VALUES (1, 'ํ๊ธธ๋', 25);
INSERT INTO testtbl1 (id, username) values (2, '์คํ');
INSERT testtbl1(username, age, id) VALUES ('ํ๋ฌ', 26, 3);
```

ํ์ด๋ธ ์ด๋ฆ ๋ค์์ ๋์ค๋ ์ด์ ์๋ต์ด ๊ฐ๋ฅํ์ง๋ง, ์๋ตํ  ๊ฒฝ์ฐ์ `VALUES` ๋ค์์ ๋์ค๋ ๊ฐ๋ค์ ์์ ๋ฐ ๊ฐ์๊ฐ ํ์ด๋ธ์ด ์ ์๋ ์ด ์์ ๋ฐ ๊ฐ์์ ๋์ผํด์ผ ํจ.

### `INSERT INTO ... SELECT` ๊ตฌ๋ฌธ 

- ๋๋์ ์ํ ๋ฐ์ดํฐ ์์ฑ
- ๋ค๋ฅธ ํ์ด๋ธ์ ๋ฐ์ดํฐ๋ฅผ ๊ฐ์ ธ์ ๋๋์ผ๋ก ์๋ ฅํ๋ ํจ๊ณผ
- `SELECT` ๋ฌธ์ ์ด์ ๊ฐ์ = `INSERT` ํ  ํ์ด๋ธ์ ์ด์ ๊ฐ์
- ํ์ด๋ธ ์ ์๊น์ง ์๋ตํ๋ ค๋ฉด `CREATE TABLE ... SELECT` ๊ตฌ๋ฌธ์ ์ฌ์ฉ

```SQL
INSERT INTO tablename (column1, column2, ...)
	SELECT ... ;
```
```SQL
-- EXAMPLE
INSERT INTO testtbl4 
SELECT emp_no, first_name, last_name
	FROM employees.employees;
```


## UPDATE

๋ฐ์ดํฐ๋ฅผ ์์ ํ๋ ๊ตฌ๋ฌธ

```SQL
UPDATE {ํ์ด๋ธ์ด๋ฆ}
	SET {column1=value1, ...}
	WHERE {์กฐ๊ฑด};
```

- `WHERE` ์ ์ ์๋ต ๊ฐ๋ฅํ๋ ์๋ตํ๋ฉด ํ์ด๋ธ์ ์ ์ฒด ํ์ด ๋ณ๊ฒฝ๋๋ฏ๋ก ๋ฐ๋์ ์ฃผ์ํ  ๊ฒ.

```SQL
UPDATE testtbl4 SET lname='์์' WHERE id = 10005;
UPDATE buytbl SET price=price*1.5 WHERE prodName='๋ชจ๋ํฐ';
```



## DELETE FROM

- ํ ๋จ์๋ก ๋ฐ์ดํฐ๋ฅผ ์ญ์ ํ๋ ๊ตฌ๋ฌธ
- `WHERE`์ ์ด ์๋ต๋๋ฉด ์ ์ฒด ๋ฐ์ดํฐ๋ฅผ ์ญ์ 

```SQL
DELETE FROM {table} WHERE {condition};
DELETE FROM testtbl4 WHERE fname='Aamer';
```



## ์กฐ๊ฑด๋ถ ๋ฐ์ดํฐ ์๋ ฅ, ๋ณ๊ฒฝ

- ๊ธฐ๋ณธ ํค๊ฐ ์ค๋ณต๋ ๋ฐ์ดํฐ๋ฅผ ์๋ ฅํ ๊ฒฝ์ฐ: ์ค๋ฅ๋ก ์๋ ฅ ๋ถ๊ฐ
- `INSERT IGNORE INTO`
  - ์๋ฌ ๋ฐ์ํด๋ ๋ค์ ๊ตฌ๋ฌธ์ผ๋ก ๋์ด๊ฐ๊ฒ ์ฒ๋ฆฌ
  - ์๋ฌ ๋ฉ์ธ์ง๋ฅผ ๋ณด๋ฉด ์ ์ฉ๋์ง ์์ ๊ตฌ๋ฌธ์ด ์ด๋๊ฒ์ธ์ง ๊ตฌ๋ถ ๊ฐ๋ฅ
- `ON DUPLICATE KEY UPDATE`
  - ๊ธฐ๋ณธ ํค๊ฐ ์ค๋ณต๋๋ฉด ๋ฐ์ดํฐ๋ฅผ ์์ ๋๋๋ก ํ๋ ๊ตฌ๋ฌธ


# ๐ WITH์ ๊ณผ CTE

## WITH ์ ๊ณผ CTE ๊ฐ์

- `WITH` ์ ์ `CTE`(Common Table Expression: ๊ณตํต ํ์ด๋ธ ํํ)๋ฅผ ํํํ๊ธฐ ์ํ ๊ตฌ๋ฌธ.
- `CTE`๋ ๊ธฐ์กด์ ๋ทฐ, ํ์ ํ์ด๋ธ, ์์ ํ์ด๋ธ ๋ฑ์ ๋์ ํ  ์ ์์ผ๋ฉฐ ๊ฐ๊ฒฐํ ์์ผ๋ก ๋ณด์ฌ์ง.
- ์์๋ก ์์ฑ๋๋ ํ์ด๋ธ

## ๋น์ฌ๊ท์  CTE

๋จ์ํ ํํ, ๋ณต์กํ ์ฟผ๋ฆฌ๋ฌธ์ฅ์ ๋จ์ํํ๋๋ฐ ์ ํฉ

```SQL
WITH CTE_ํ์ด๋ธ์ด๋ฆ(์ด ์ด๋ฆ)
AS
(
	<์ฟผ๋ฆฌ๋ฌธ>
)
SELECT ์ด ์ด๋ฆ FROM CTE_ํ์ด๋ธ์ด๋ฆ;
```

- **๋ทฐ๋ ๊ณ์ ์กด์ฌ**ํด์ ๋ค๋ฅธ ๊ตฌ๋ฌธ์์๋ ์ฌ์ฉ ๊ฐ๋ฅํ์ง๋ง, **CTE์ ํ์ ํ์ด๋ธ์ ๊ตฌ๋ฌธ์ด ๋๋๋ฉด ์๋ฉธ**๋จ.
- ์ค๋ณต CTE์ด ํ์ฉ๋จ