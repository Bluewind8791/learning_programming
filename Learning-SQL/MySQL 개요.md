# DBMS 개요

DBMS에 대한 대략적인 내용과 MySQL에 대해서 알아봅니다.

## 데이터베이스의 정의와 특징

### DB(DataBase)

- '데이터의 집합'
- '데이터의 저장공간' 자체
- 여러명의 사용자가 동시에 접근이 가능해야 합니다.


### DBMS(DB Management System)

- DB를 관리, 운영하는 역할을 하는 시스템입니다.

![](https://velog.velcdn.com/images/bluewind8791/post/38c99200-1109-4b41-8c96-e59c0cb964d8/image.png)

## DB/DBMS의 특징

- 자료의 무결성 (Integrity)
  - **데이터베이스 안의 데이터는 오류가 없어야 합니다**
  - 제약 조건(Constrain)이라는 특성을 가집니다.
- 데이터의 독립성
  - DB 크기를 변경하거나 데이터 파일의 저장소 변경 시 기존의 작성된 응용 프로그램은 영향을 받지 않아야 합니다.
- 보안
  - 허가된 사람만 접근할 수 있어야 하며 권한을 모두 다르게 줄 수 있습니다.
- 데이터 중복의 최소화
  - 동일한 데이터가 여러개 중복되어 저장되는것을 방지합니다.
- 응용 프로그램 제작 및 수정이 쉬워짐
- 데이터 안정성 향상
  - 대부분의 DBMS가 제공하는 백업/복원 기능을 이용하여 원상 복원/복구하는 방법이 명확해졌습니다.



## DB/DBMS의 분류

### 계층형 DBMS
![](https://velog.velcdn.com/images/bluewind8791/post/b9d15a93-f221-43f6-a881-34562b01f1e4/image.png)
- 처음으로 나온 DBMS 개념이며 Tree형태인 1:N 관계를 가지고 있습니다.
- 주어진 상태에서의 검색은 빠르다는 장점이 있습니다.
- 처음 구축한 이후 그 구조를 변경하기가 상당히 까다롭고, 접근 유연성이 부족하여 임의의 검색이 어렵다는 단점이 있습니다.


### 망형 DBMS
![](https://velog.velcdn.com/images/bluewind8791/post/498c4039-c7b8-4063-91d0-574f8965905c/image.png)
- 계층형 DBMS의 문제점을 개선하기 위하여 개발되었습니다.
- 1:1 / 1:N / 다:다 관계를 지원하여 효과적이고 빠른 데이터 추출이 가능합니다.
- 복잡한 내부 포인터를 사용하여 프로그래머가 모든 구조를 이해해야만 프로그램이 작성가능한 단점이 있습니다.


### **관계형 DBMS**
![](https://velog.velcdn.com/images/bluewind8791/post/6675d358-5167-4f0a-88e0-6b3860608b55/image.png)

- Relational DBMS
- DB를 Table이라는 최소 단위로 구성하고, Table은 행과 열로 구성한 구조입니다.
- 구조를 바꾸는 것이 용이하여 유지보수 측면에서 편리해졌으며, 대용량 데이터의 관리와 데이터 무결성을 보장하는 장점이 있습니다.
- 데이터가 많아질 수록 시스템이 전반적으로 느려진다는 단점이 있습니다. 하지만 하드웨어의 기술 발달로 상쇄되고 있는 추세입니다.


## SQL

- 관계형 데이터베이스에서 사용되는 DBMS의 데이터 구축/관리/활용을 위하여 사용되는 언어를 SQL(Structured Query Language)이라고 합니다.
- DBMS 개발 회사와 독립적이며 다른 시스템으로의 이식성이 좋습니다.
- 대화식 언어이며 표준 SQL가 꾸준히 발전 중입니다.

![](https://velog.velcdn.com/images/bluewind8791/post/55b541e6-2345-443f-81cb-58cc0e2dd63a/image.png)


# MySQL 전체 운영 실습

## 테이블 외의 DB 개체의 활용

### Index
- 데이터베이스 '튜닝'의 개념
  - DB 성능 향상
  - 쿼리에 응답한느 시간 단축
- 책 뒤에 붙어있는 '색인'과 같은 개념
- 데이터의 양이 많을수록 효과적으로 작용
- 테이블의 열 단위에 생성

### View
- 가상의 테이블
- 보안상의 이유로 사용
- 실제 행 데이터를 가지고 있지 않으며, 실제 테이블에 링크된 개념
- 뷰를 `SELECT` 시에 실제 테이블의 데이터를 조회하는 것과 동일한 결과

```sql
CREATE VIEW uv_memberTBL 
AS
	SELECT memberName, memberAddress FROM userTBL ;

SELECT * FROM uv_memberTBL ;

# dictionary (테이블 정보를 확인)
select * from information_schema.tables where table_schema='shopping_db';
# view만 확인
select * from information_schema.views where table_schema='shopping_db';
```


### Stored Procedure
- MySQL에서 제공해주는 프로그래밍 기능
- SQL문을 하나로 묶어 편리하게 사용하는 기능
- 다른 프로그래밍 언어와 같은 기능을 담당할 수도 있다.
- 실질적으로 DB 개발자가 주로 하는 것.
- `SELECT`문을 매번 하나하나 실행하는것이 아니라 스토어드 프로시저로 만들어 놓은 후 호출하면 간단하다.

```sql
SELECT * FROM userTBL WHERE memberName = '당탕이';
SELECT * FROM productTBL WHERE productName = '냉장고';

DELIMITER //
CREATE PROCEDURE myProc()
BEGIN
	SELECT * FROM userTBL WHERE memberName = '당탕이' ;
	SELECT * FROM productTBL WHERE productName = '냉장고' ;
END // 
DELIMITER ;

CALL myProc() ;
```


### Trigger
- 테이블에 부착되어 테이블에 `INSERT`나 `UPDATE` 또는 `DELETE` 작업이 발생되면 실행되는 코드.



---


정보시스템 구축 절차 요약
- 5가지 단계

분석 / 설계 / 구현 / 시험 / 유지보수


※ 데이터베이스 모델링
- 현실에서 사용되는 데이터를 어떻게 
  테이블에 올려 놓을 것인지 결정하는 과정.



- Foreign Key (외래 키) : 두 테이블의 관계를 맺어주는 키

- Table 생성 시 Column 만 초기 설정을 함. 

- PK (Primary Key) : 기본 테이블로 지정
  중복되는 자료가 있어서는 안되며(Unique)
  비어있어서는 안되는 기본 테이블

- NN (Not NULL)  : 빈값 안됨
- UQ (Unique) : 중복 값을 넣을 수 없음
- Binary : 데이터를 이진 문자열로 저장함 (010101 같은)
- Unsigned data type : - 범위 삭제
- Zero Filled : 컬럼 크기보다 작은 값을 넣었을 경우 0으로 채운 뒤 삽입시킴


```sql
use shopping_db;

select * from userTBL;
select memberName, memberAddress from userTBL;
select * from usertbl where membername = '지운이';

# select 열이름 from 테이블 이름 where 조건


create table `my TestTBL` (id INT);
drop table `my TestTBL`;
# 가급적이면 이름에 띄어쓰기 안하는것을 권장
# 띄어쓰기 할때는 ``를 사용.



CREATE TABLE indexTBL (first_name varchar(14), last_name varchar(16) , hire_date date);
INSERT INTO indexTBL 
	SELECT first_name, last_name, hire_date 
	FROM employees.employees
	LIMIT 500;


SELECT * FROM indexTBL;

SELECT * FROM indexTBL WHERE first_name = 'Mary';

CREATE INDEX idx_indexTBL_firstname ON indexTBL(first_name);
# INDEX 만들기

SELECT * FROM indexTBL WHERE first_name = 'Mary';
```
