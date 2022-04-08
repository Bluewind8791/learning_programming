-- Query all columns for all American cities in the CITY table with populations larger than 100000. The CountryCode for America is USA.
SELECT * FROM CITY WHERE CITY.POPULATION >= 100000 AND CITY.COUNTRYCODE = 'USA';



-- Query the NAME field for all American cities in the CITY table with populations larger than 120000.
-- The CountryCode for America is USA.
SELECT NAME FROM CITY WHERE POPULATION > 120000 AND COUNTRYCODE = 'USA';



-- Query all columns (attributes) for every row in the CITY table.
SELECT * FROM CITY;



-- Query all columns for a city in CITY with the ID 1661.
SELECT * FROM CITY WHERE CITY.ID = 1661;



-- Query all attributes of every Japanese city in the CITY table. The COUNTRYCODE for Japan is JPN.
SELECT * FROM CITY WHERE CITY.COUNTRYCODE = 'JPN';



-- Query the names of all the Japanese cities in the CITY table. The COUNTRYCODE for Japan is JPN.
SELECT NAME FROM CITY WHERE CITY.COUNTRYCODE = 'JPN';



-- Query a list of CITY and STATE from the STATION table.
SELECT CITY, STATE FROM STATION;



/*
Query a list of CITY names from STATION for cities that have an even ID number. 
Print the results in any order, but exclude duplicates from the answer.
*/
SELECT DISTINCT(CITY) FROM STATION WHERE (ID % 2 = 0);
-- 중복 쿼리를 삭제하려면 DISTINCT 쿼리를 사용한다.



/*
Find the difference between the total number of CITY entries in the table and the number of distinct CITY entries in the table.
테이블에 있는 총 CITY 항목 수와 테이블에 있는 고유한 CITY 항목 수 사이의 차이를 찾으십시오.
*/
SELECT COUNT(CITY) - COUNT(DISTINCT(CITY)) FROM STATION;



/*
Query the two cities in STATION with the shortest and longest CITY names, 
as well as their respective lengths (i.e.: number of characters in the name).
If there is more than one smallest or largest city, choose the one that comes first when ordered alphabetically.
ABC 3
PQRS 4
*/
SELECT CITY, CHAR_LENGTH(CITY) AS len
FROM STATION
GROUP BY CITY
ORDER BY len ASC, CITY
LIMIT 1
;
SELECT CITY, CHAR_LENGTH(CITY) AS len
FROM STATION
GROUP BY CITY
ORDER BY len DESC, CITY
LIMIT 1
;
-- 다중정렬: ORDER BY 기준1, 기준2
-- CHAR_LENGTH: 띄어쓰기 미포함 문자열 개수



/*
Query the list of CITY names starting with vowels (i.e., a, e, i, o, or u) from STATION.
Your result cannot contain duplicates.
*/
SELECT DISTINCT(CITY) FROM STATION WHERE SUBSTRING(CITY, 1, 1) IN (
    'a', 'e', 'i', 'o', 'u'
);
-- SUBSTRING('문자열', '시작지점', '길이') : 문자열을 시작지점에서부터 길이만큼 읽어들인다.



/*
Query the list of CITY names ending with vowels (a, e, i, o, u) from STATION. Your result cannot contain duplicates.
*/
SELECT DISTINCT(CITY) FROM STATION WHERE SUBSTRING(CITY, -1, 1) IN (
    'a', 'e', 'i', 'o', 'u'
);
-- 마지막 문자열은 시작 지점을 -1으로 하면 가져올 수 있다.



/*
Query the list of CITY names from STATION which have vowels (i.e., a, e, i, o, and u) as both their first and last characters.
Your result cannot contain duplicates.
*/
SELECT DISTINCT(CITY) FROM STATION
WHERE
    SUBSTRING(CITY, -1, 1) IN ('a', 'e', 'i', 'o', 'u') AND
    SUBSTRING(CITY, 1, 1) IN ('a', 'e', 'i', 'o', 'u')
;



/*
Query the list of CITY names from STATION that do not start with vowels.
Your result cannot contain duplicates.
*/
SELECT DISTINCT(CITY) FROM STATION
WHERE SUBSTRING(CITY, 1, 1) NOT IN ('a', 'e', 'i', 'o', 'u');



/*
Query the list of CITY names from STATION that do not end with vowels.
Your result cannot contain duplicates.
*/
SELECT DISTINCT(CITY) FROM STATION
WHERE SUBSTRING(CITY, -1, 1) NOT IN ('a', 'e', 'i', 'o', 'u');



/*
Query the list of CITY names from STATION that either do not start with vowels or do not end with vowels.
Your result cannot contain duplicates.
*/
SELECT DISTINCT(CITY) FROM STATION
WHERE
    SUBSTRING(CITY, -1, 1) NOT IN ('a', 'e', 'i', 'o', 'u') OR
    SUBSTRING(CITY, 1, 1) NOT IN ('a', 'e', 'i', 'o', 'u')
;



/*
Query the list of CITY names from STATION that do not start with vowels and do not end with vowels.
Your result cannot contain duplicates.
*/
SELECT DISTINCT(CITY) FROM STATION
WHERE
    SUBSTRING(CITY, -1, 1) NOT IN ('a', 'e', 'i', 'o', 'u') AND
    SUBSTRING(CITY, 1, 1) NOT IN ('a', 'e', 'i', 'o', 'u')
;




/*
Query the Name of any student in STUDENTS who scored higher than 75 Marks.
Order your output by the last three characters of each name.
If two or more students both have names ending in the same last three characters (i.e.: Bobby, Robby, etc.),
secondary sort them by ascending ID.
*/
SELECT NAME
FROM STUDENTS WHERE MARKS > 75
ORDER BY SUBSTRING(NAME, -3, 3), ID;
-- 마지막 3자리 문자는 뒤에서부터 세번째부터 3개의 문자열을 가져오면 된다.



/*
Write a query that prints a list of employee names (i.e.: the name attribute) from the Employee table in alphabetical order.
*/
SELECT name FROM Employee ORDER BY name;



/*
Write a query that prints a list of employee names (i.e.: the name attribute) for employees in Employee
having a salary greater than $2000 per month who have been employees for less than 10 months.
Sort your result by ascending employee_id.
*/
SELECT NAME FROM Employee WHERE salary > 2000 AND months < 10;