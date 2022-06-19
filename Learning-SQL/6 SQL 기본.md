# 🌜 SELECT 문

## SELECT...FROM

원하는 데이터를 가져와주는 기본적인 구문

```sql
SELECT {column}
FROM {table}
WHERE {where_condition}
GROUP BY {col_name | expression | position} # 무엇을 기준으로 해서 평균이나 합계 최댓값 등을 구할때
HAVING {where_condition} 
ORDER BY {col_name | expression | position} # 정렬
```
```sql
SELECT {열 이름}
FROM {테이블 이름}
WHERE {조건}
```

선택된 DB가 `employees`라면 다음 두 쿼리는 동일함.

```sql
SELECT * FROM employees; # 테이블의 모든 행 선택 및 진입
SELECT * FROM employees.employees; # DB안의 Table 선택 및 진입
```


`employees` 테이블 안의 특정 column 을 `SELECT`

```sql
SELECT last_name, first_name FROM employees;
```

- Column의 이름을 변경하여 출력
- `AS`는 생략이 가능
- ""도 생략이 가능하나 중간에 공백이있으면 생략 불가.

```sql
SELECT last_name AS "성", first_name AS "이름" FROM employees;
SELECT last_name "성", first_name "이름" FROM employees;
```



## SELECT...FROM...WHERE

### 기본적인 WHERE 절

조건에 부합하는 대상을 `SELECT` 합니다.

```sql
SELECT * FROM usertbl WHERE name='김경호'; -- 정확한 조건
```


### 관계 연산자의 사용

- `OR` 연산자
- `AND` 연산자
- 조건 연산자 (`=`, `<`, `>`, `<=`, `>=`, `!=` 등)
- 관계 연산자 (`NOT`, `AND`, `OR` 등)


### BETWEEN...AND 

데이터가 숫자로 구성되어 있으며 연속적인 값

```sql
SELECT * FROM usertbl WHERE height BETWEEN 180 AND 190;
```

### IN(...)

이산적인 값의 조건

```sql
SELECT * FROM usertbl WHERE addr IN ('서울', '경기');
```


### LIKE

문자열의 내용 부분별 조건 검색

```sql
SELECT * FROM usertbl WHERE name LIKE '%경호';
SELECT * FROM usertbl WHERE name LIKE '%경%';
SELECT * FROM usertbl WHERE name LIKE '_경호';
```

## ANY/ALL/SOME/서브쿼리


### 서브 쿼리 (SubQuery, 하위쿼리)

쿼리문 안에 또 쿼리문이 있는 것

```SQL
SELECT height FROM usertbl WHERE name = '김경호'; -- 이름이 김경호이며
SELECT * FROM usertbl WHERE height >= 177; -- 키가 177 이상인 사람

-- 위의 두 조건을 서브쿼리로 합친 결과
SELECT * FROM usertbl
WHERE height >= (SELECT height FROM usertbl WHERE name ='김경호');
```


### ANY
  - 서브쿼리의 여러 결과 중 한가지만 만족해도 가능
  - `SOME`은 `ANY`와 동일한 의미로 사용
  - `= ANY(서브쿼리)`는 `IN(서브쿼리)`와 동일한 의미


### ALL
  - 서브쿼리의 결과 중 여러 개의 결과를 모두 만족해야 함.

- `> ANY` : 최소값 보다 큰
- `> ALL` : 최대값 보다 큰
- `< ANY` : 최대값 보다 작은
- `< ALL` : 최소값 보다 작은

```sql
-- 서울인 사람들이 다수임으로 ANY 사용해야함
SELECT * FROM usertbl WHERE height >=ANY (SELECT height FROM usertbl WHERE addr='서울');
```

## 원하는 순서대로 정렬

### ORDER BY 절

- 원하는 순서대로 정렬하여 출력
- default 값은 오름차순 (`ASC`)
- 내림차순으로 정렬하기 위해서는 `DESC`를 사용

```sql
-- height를 기준으로 오름차순 정렬
SELECT * FROM usertbl ORDER BY height;

-- Column 의 번호(순서)를 적어서 정렬할 수 있다.
SELECT * FROM usertbl ORDER BY 7;

-- `ORDER BY` 구문을 혼합하여 사용
SELECT name, height FROM usertbl ORDER BY height DESC, name ASC;
```


### DISTINCT

- 중복된 것을 골라서 세기 어려울 때 사용하는 구문
- 중복된 것은 1개만 보여주면서 출력
- 테이블의 크기가 클수록 효율적


```sql
-- addr, mobile1 으로 중복선택하여 DISTINCT 하면 의미 없다.
SELECT DISTINCT addr FROM usertbl;
```


### LIMIT

- 출력하는 개수를 제한하는 구문
- 전체에서 상위 n 개만 출력

```sql
SELECT * FROM usertbl LIMIT 3;

-- 3번부터 5개의 데이터를 출력 (4,5,6,7,8)
SELECT * FROM usertbl LIMIT 3, 5;
```




## GROUP BY 및 HAVING 그리고 집계 함수


### GROUP BY 절

- 그룹으로 묶어주는 역할
- 집계 함수와 함께 사용

```sql
SELECT userid, SUM(amount) FROM buytbl GROUP BY userID;
```

`GROUP BY`와 자주 사용되는 집계함수를 포함

```sql
SELECT name, height
FROM usertbl 
WHERE 
	height=(SELECT MAX(height) FROM usertbl)
	or
	height=(SELECT MIN(height) FROM usertbl)
;
```

### 집계 함수 (통계 함수)

함수명 | 설명 |
-|-|
SUM() | 합계
AVG() | 평균
MIN() | 최소값
MAX() | 최대값
COUNT()	| 개수를 카운트
COUNT(DISTINCT)	| 개수 카운트 (중복은 1개만 인정)
STDEV()	| 표준편차
VAR_SAMP() | 분산


```sql
-- 전체 구매자가 구매한 물품의 개수 평균
SELECT AVG(amount) AS "구매한 수량 평균" FROM buytbl;
```



### HAVING

- `WHERE`과 비슷한 개념이지만 **집계 함수에 대해서 필터링**을 하는 것
- `GROUP BY` 에서는 `WHERE`을 쓸 수 없으며 `HAVING`을 사용해야 한다.
- `HAVING`절은 반드시 `GROUP BY`절 다음에 나와야 한다.

```sql
SELECT userid, SUM(amount*price) AS "총 구매액"
FROM buytbl
GROUP BY userid
HAVING SUM(price*amount) >= 1000;
```



### ROLLUP

- 중간 합계 (소계) 가 필요할때 사용
- `GROUP BY`절과 함께 `WITH ROLLUP`문 사용

```sql
SELECT num, groupName, SUM(price*amount) AS 'Cost'
FROM buytbl
GROUP BY groupName, num
WITH ROLLUP;
```





## SQL의 분류

- DML (Data Manipuation Language : 데이터 조작 언어)
  - 데이터를 다루는 언어
  - `SELECT`, `INSERT`, `UPDATE`, `DELETE` 구문이 해당
  - 트랜잭션이 발생하는 SQL도 포함 (임시로 적용 시키는것, 취소 가능한 것)

- DDL (Data Definition Language: 데이터 정의 언어)
  - `CREATE`, `DROP`, `ALTER` 자주 사용
  - DDL은 트랜젝션 발생X (취소 불가)

- DCL (Data Control Language: 데이터 제어 언어)
  - 사용자에게 권한을 부여하는 언어
  - `GRANT`(권한 부여), `REVOKE`(권한 회수), `DENY`



# 🌜 데이터의 변경


## INSERT

```SQL
INSERT [INTO] 테이블[(colum1, column2, ...)] VALUES (value1, value2 ... )

-- 가장 일반적인 형식
INSERT INTO testtbl1 VALUES (1, '홍길동', 25);
INSERT INTO testtbl1 (id, username) values (2, '설현');
INSERT testtbl1(username, age, id) VALUES ('하늬', 26, 3);
```

테이블 이름 다음에 나오는 열은 생략이 가능하지만, 생략할 경우에 `VALUES` 다음에 나오는 값들의 순서 및 개수가 테이블이 정의된 열 순서 및 개수와 동일해야 함.

### `INSERT INTO ... SELECT` 구문 

- 대량의 샘플 데이터 생성
- 다른 테이블의 데이터를 가져와 대량으로 입력하는 효과
- `SELECT` 문의 열의 개수 = `INSERT` 할 테이블의 열의 개수
- 테이블 정의까지 생략하려면 `CREATE TABLE ... SELECT` 구문을 사용

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

데이터를 수정하는 구문

```SQL
UPDATE {테이블이름}
	SET {column1=value1, ...}
	WHERE {조건};
```

- `WHERE` 절은 생략 가능하나 생략하면 테이블의 전체 행이 변경되므로 반드시 주의할 것.

```SQL
UPDATE testtbl4 SET lname='없음' WHERE id = 10005;
UPDATE buytbl SET price=price*1.5 WHERE prodName='모니터';
```



## DELETE FROM

- 행 단위로 데이터를 삭제하는 구문
- `WHERE`절이 생략되면 전체 데이터를 삭제

```SQL
DELETE FROM {table} WHERE {condition};
DELETE FROM testtbl4 WHERE fname='Aamer';
```



## 조건부 데이터 입력, 변경

- 기본 키가 중복된 데이터를 입력한 경우: 오류로 입력 불가
- `INSERT IGNORE INTO`
  - 에러 발생해도 다음 구문으로 넘어가게 처리
  - 에러 메세지를 보면 적용되지 않은 구문이 어느것인지 구분 가능
- `ON DUPLICATE KEY UPDATE`
  - 기본 키가 중복되면 데이터를 수정되도록 하는 구문


# 🌜 WITH절과 CTE

## WITH 절과 CTE 개요

- `WITH` 절은 `CTE`(Common Table Expression: 공통 테이블 표현)를 표현하기 위한 구문.
- `CTE`는 기존의 뷰, 파생 테이블, 임시 테이블 등을 대신할 수 있으며 간결한 식으로 보여짐.
- 임시로 생성되는 테이블

## 비재귀적 CTE

단순한 형태, 복잡한 쿼리문장을 단순화하는데 적합

```SQL
WITH CTE_테이블이름(열 이름)
AS
(
	<쿼리문>
)
SELECT 열 이름 FROM CTE_테이블이름;
```

- **뷰는 계속 존재**해서 다른 구문에서도 사용 가능하지만, **CTE와 파생 테이블은 구문이 끝나면 소멸**됨.
- 중복 CTE이 허용됨