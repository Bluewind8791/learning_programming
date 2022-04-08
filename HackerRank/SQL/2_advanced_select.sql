/*
Write a query identifying the type of each record in the TRIANGLES table using its three side lengths.
Output one of the following statements for each record in the table:

Equilateral: It's a triangle with 3 sides of equal length.
Isosceles: It's a triangle with 2 sides of equal length.
Scalene: It's a triangle with 3 sides of differing lengths.
Not A Triangle: The given values of A, B, and C don't form a triangle.
*/
SELECT 
CASE
    WHEN A + B > C AND B + C > A AND A + C > B -- 삼각형의 조건
    THEN
        CASE
            WHEN A = B AND B = C THEN 'Equilateral' -- 정사각형
            WHEN A = B OR A = C OR B = C THEN 'Isosceles' -- 이등변삼각형
            ELSE 'Scalene' -- 세변의 길이가 다른 삼각형
        END
    ELSE 'Not A Triangle'
END
FROM TRIANGLES;
-- CASE 
--     when 조건1  then 결과값1
--     when 조건2  then 결과값2
--     else 결과값5
-- END




/*
1. OCCUPATIONS의 모든 이름을 알파벳순으로 나열한 목록을 쿼리합니다.
바로 뒤에 괄호로 각 직업의 첫 글자가 옵니다.
For example: AnActorName(A), ADoctorName(D), AProfessorName(P), and ASingerName(S).
*/
SELECT CONCAT(NAME, '(', SUBSTRING(Occupation, 1, 1), ')')
FROM OCCUPATIONS
ORDER BY Name
;
/*
2. OCCUPATIONS에서 각 직업의 발생 횟수를 쿼리합니다.
발생 항목을 오름차순으로 정렬하고 다음 형식으로 출력합니다.

There are a total of [occupation_count] [occupation]s.

여기서 [occupation_count]는 OCCUPATIONS의 직업 발생 횟수이고 [occupation]은 소문자 직업 이름입니다.
둘 이상의 직업이 동일한 [occupation_count]를 갖는 경우 알파벳순으로 정렬해야 합니다.
*/
SELECT
    CONCAT('There are a total of ', COUNT(Occupation), " ", LOWER(Occupation), 's.')
FROM OCCUPATIONS
GROUP BY Occupation
ORDER BY COUNT(Occupation), Occupation
;
-- CONCAT 명령어로 쿼리 결과값을 원하는 대로 꾸며줄 수 있다.




