-- 5 Show the name and population for France, Germany, Italy
SELECT name, population
FROM world
WHERE name IN ('France', 'Germany', 'Italy');


-- 6 Show the countries which have a name that includes the word 'United'
SELECT name FROM world WHERE name LIKE '%United%';


-- 7 Two ways to be big
SELECT name, population, area
FROM world 
WHERE area >= 3000000 OR population >= 250000000;


-- 8 Exclusive OR (XOR).
-- Show the countries that are big by area (more than 3 million) or big by population (more than 250 million) but not both.
-- Show name, population and area.
SELECT name, population, area
FROM world
WHERE 
    (population > 250000000 or area > 3000000)
    AND
    NOT(population > 250000000 AND area > 3000000);


-- 9 Show the name and population in millions and the GDP in billions for the countries of the continent 'South America'.
-- Use the ROUND function to show the values to two decimal places.
SELECT name, ROUND(population/1000000,2), ROUND(gdp/1000000000,2) 
FROM world
WHERE continent = 'South America';


-- 10 Show the name and per-capita GDP for those countries with a GDP of at least one trillion (1000000000000; that is 12 zeros).
-- Round this value to the nearest 1000.
SELECT name, ROUND(gdp/population,-3)
FROM world
WHERE gdp > 1000000000000;


-- 11
SELECT name, capital
FROM world
WHERE LEN(name)=LEN(capital);


-- 12 The capital of Sweden is Stockholm. Both words start with the letter 'S'.
SELECT name, capital
FROM world
WHERE
    LEFT(name,1)=LEFT(capital,1)
    AND
    name!=capital;


-- 13 Equatorial Guinea and Dominican Republic have all of the vowels (a e i o u) in the name.
-- They don't count because they have more than one word in the name.
SELECT name FROM world
WHERE 
    name LIKE '%a%' 
    AND name LIKE '%e%' 
    AND name LIKE '%i%' 
    AND name LIKE '%o%' 
    AND name LIKE '%u%'
    AND name NOT LIKE '% %';