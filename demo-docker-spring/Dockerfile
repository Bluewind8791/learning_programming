# 베이스 이미지 + 이미지 별칭
FROM openjdk:11-jdk-slim AS builder

# 아래의 파일 및 디렉토리 복사
COPY gradlew .
COPY gradlew.bat .
COPY build.gradle .
COPY settings.gradle .

COPY gradle gradle
COPY src src

# gradlew 실행권한 부여
RUN chmod +x ./gradlew
# gradlew를 사용하여 실행 가능한 jar 파일 생성
RUN ./gradlew bootJar 

# 베이스 이미지
FROM openjdk:11-jdk-slim
# builder 이미지에서 build/libs/*.jar 파일을 app.jar로 복사
COPY --from=builder build/libs/*.jar app.jar

# 컨테이너 Port 노출
EXPOSE 8080
# jar 파일 실행
ENTRYPOINT ["java","-jar","/app.jar"]
