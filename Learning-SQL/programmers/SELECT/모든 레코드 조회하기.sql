-- 동물 보호소에 들어온 모든 동물의 정보를 
-- ANIMAL_ID순으로 조회하는 SQL문을 작성해주세요. 
-- SQL을 실행하면 다음과 같이 출력되어야 합니다.


SELECT * from animal_ins group by animal_id;

-- GROUP BY 는 그룹화 하여 데이터를 조회합니다.