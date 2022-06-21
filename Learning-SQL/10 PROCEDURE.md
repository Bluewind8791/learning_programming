
■ STORED PROCEDURE

- 쿼리문의 집합으로 어떠한 동작을 일괄 처리하기 위한 용도
- 쿼리 모듈화
	- 필요할때마다 호출
	- CALL procedureName();
- 수정 : ALTER PROCEDURE
- 삭제 : DROP PROCEDURE
- 매개 변수(Parameter)의 사용
	- 입력 매개변수 : IN name data_form
	- 출력 매개 변수 : OUT name data_form


- 형식
```sql
DELIMITER $$
	CREATE PROCEDURE procedureName( IN or OUT )
	BEGIN
		coding...
	END $$
	DELIMITER ;

CALL procedureName( );
```



■ STORED FUNCTION

- 형식
```sql
DELIMITER $$
	CREATE FUNCTION functionName( in_parameter )
		RETURNS form
	BEGIN
		coding...
		RETURN return;
	END $$
	DELIMITER ;

SELECT functionName();
```
- PARAMETER은 모두 입력(IN) 파라미터
- RETURNS문으로 반환할 값의 데이터 형식 지정
- RETURN 으로 하나의 값 반환

- 스토어드 함수를 사용하기 위해서는 권한 허용해야함
```sql
SET GLOBAL log_bin_trust_function_creators = 1;
```


■ 커서 (CURSOR)
- Stored Procedure 내부에 사용

- 처리 순서
커리 선언 -> 반복 조건 선언 -> 커서 열기 ->
	LOOP ~(커서에서 데이터 가져오기 -> 데이터 처리)~ END -> 커서 닫기

```sql
DELIMITER $$
CREATE PROCEDURE cursorProc()
BEGIN
	DECLARE userHeight INT;
	DECLARE cnt INT DEFAULT 0;
	DECLARE totalHeight INT default 0;
	DECLARE endofRow BOOLEAN DEFAULT FALSE;
```



■ 트리거(Trigger)
- 어떠한 조건이 충족(이벤트)되면 자동으로 실행.
- 테이블에 Insert, Update, Delete 등 이벤트 발생 시 작동
- 테이블에 부착되는 코드 (뷰 부착 불가)

- AFTER Trigger
- BEFORE Trigger

```sql
delimter ##
CREATE TRIGGER testtrg
	after delete
	ON testtbl FOR EACH ROW
BEGIN
	SET @msg = '가수 그룹이 삭제됨';
END ##
delimiter ;
```