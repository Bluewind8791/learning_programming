/*
각 이름이 알파벳순으로 정렬되고
해당 직업 아래에 표시되도록 OCCUPATIONS의 Occupation 열을 Pivot 합니다.
출력 열 헤더는 각각 Doctor, Professor, Singer 및 Actor여야 합니다.
참고: 직업에 해당하는 이름이 더 이상 없으면 NULL을 인쇄합니다.
*/

-- 1. 가상테이블을 만듭니다.
SELECT
    CASE WHEN Occupation = 'Doctor'    THEN name END AS Doctor,
    CASE WHEN Occupation = 'Professor' THEN name END AS Professor,
    CASE WHEN Occupation = 'Singer'    THEN name END AS Singer,
    CASE WHEN Occupation = 'Actor'     THEN name END AS Actor
FROM OCCUPATIONS;

/*
2. Occupation 에 대한 인덱스 열을 RowNumber 로 생성합니다.
사용자 정의 변수를 만듭니다.
아래 코드는 "RowNumber" 열만 제공합니다.

- 사용자 정의 변수
SET @변수 = VALUE;
SET @변수 := VALUE;
SELECT @변수 := VALUE;
*/
SET @r1 = 0, @r2 = 0, @r3 = 0, @r4 = 0;
SELECT CASE
    WHEN Occupation = 'Doctor'    THEN (@r1 := @r1 + 1)
    WHEN Occupation = 'Professor' THEN (@r2 := @r2 + 1)
    WHEN Occupation = 'Singer'    THEN (@r3 := @r3 + 1)
    WHEN Occupation = 'Actor'     THEN (@r4 := @r4 + 1)
END AS RowNumber
FROM OCCUPATIONS;



-- 3. 1번과 2번 두 테이블을 합칩니다.
SET @r1 = 0, @r2 = 0, @r3 = 0, @r4 = 0;
SELECT 
    CASE
        WHEN Occupation = 'Doctor'    THEN (@r1 := @r1 + 1)
        WHEN Occupation = 'Professor' THEN (@r2 := @r2 + 1)
        WHEN Occupation = 'Singer'    THEN (@r3 := @r3 + 1)
        WHEN Occupation = 'Actor'     THEN (@r4 := @r4 + 1)
    END AS RowNumber,
    CASE WHEN Occupation = 'Doctor'    THEN name END AS Doctor,
    CASE WHEN Occupation = 'Professor' THEN name END AS Professor,
    CASE WHEN Occupation = 'Singer'    THEN name END AS Singer,
    CASE WHEN Occupation = 'Actor'     THEN name END AS Actor
FROM OCCUPATIONS;


/*
4. ORDER BY 를 RowNumber 으로 주고
Min/Max를 사용하여 이름이 있으면 이름을 반환하고 없으면 NULL을 반환합니다.
*/
SET @r1 = 0, @r2 = 0, @r3 = 0, @r4 = 0;
SELECT
    MIN(Doctor),
    MIN(Professor),
    MIN(Singer),
    MIN(Actor)
FROM (
    SELECT
        CASE
            WHEN Occupation = 'Doctor'    THEN (@r1 := @r1 + 1)
            WHEN Occupation = 'Professor' THEN (@r2 := @r2 + 1)
            WHEN Occupation = 'Singer'    THEN (@r3 := @r3 + 1)
            WHEN Occupation = 'Actor'     THEN (@r4 := @r4 + 1) END AS RowNumber,
        CASE WHEN Occupation = 'Doctor'    THEN name END AS Doctor,
        CASE WHEN Occupation = 'Professor' THEN name END AS Professor,
        CASE WHEN Occupation = 'Singer'    THEN name END AS Singer,
        CASE WHEN Occupation = 'Actor'     THEN name END AS Actor
    FROM OCCUPATIONS
    ORDER BY Name
    ) TEMPORARY
GROUP BY RowNumber
;
/*
쿼리 내부에 임시 테이블을 생성했기 때문에 TEMPORARY 를 적어야합니다.
GROUP BY RowNumber 가 없으면 단일 행의 값 밖에 나오지 않는다.
*/