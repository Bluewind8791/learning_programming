
21. Thread 클래스의 여러 메서드들

* Thread 우선순위

- Thread.MIN_PRIORITY(=1) ~ Thread.MIN_PRIORITY(=10)

- default 우선순위 = 5

- setPriority() / getPriority()



* join()

- 동시에 두개 이상의 쓰레드가 실행될때 다른 쓰레드의 결과를 참조해야할떄 사용

- join() 함수를 호출한 쓰레드가 not-runnable 상태가 됨
- 다른 쓰레드의 수행이 끝나면 runnable 상태로 돌아옴



* interrupt()

- 다른 쓰레드에 예외를 발생시키는 interrupt 를 보낸다.
- 쓰레드가 join(), sleep, wait 함수에 의해 non-runnable 상태일때 
  interrupt method를 호출하면
  다시 runnable 상태가 될수있음



* Thread 종료하기

- 무한 반복의 경우 while(flag) 의 flag 변수값을 false로 바꾸어 종료시킴
