class 를 이용해서  C++ 로 코드를 작성한다.

/*********************
* 스터디 : 2014.11.21 
*********************/

[스터디 내용]
1. NULL 쓰기위해서는 #include <stddef.h>를 사용해야 한다.
2. string 쓰면 연산자 overriding 가능한다.
3. class 작성시 멤버함수 명칭에서 *LinkedList는 삭제한다.
  이유 : 클래스내에 소속감이 생겨서 명칭에 구분을 위해서 추가할 필요가 없다.
4. 함수 실행시 지역변수는 컴파일러가 소멸시킨다.
5. windows 는 PE구조, linux는 ELF구조 - os별 실행파일 구조
  symbolic table

[Do do list]
1. addressBook.c / addressBook.h 파일 클래스로 변경하기
  PersonInfo 클래스내 멤버 변수는 private에 넣는다.(public 아님)
2. 연산자 overriding 구현
  = , << , ==
3. 복사 생성자 구현 - 183page 참고
4. Node 클래스도 멤버 변수는 public으로 구현

[책]
1. 컴파일러 구조와 원리 컴파일러로 배우는 언어 처리 시스템 - 저자 아오키 미네로우|역자 이영희|한빛미디어 
2. OPERATING SYSTEM CONCEPTS - 저자 Abraham Silberschatz, Peter B. Galvin, Greg Gagne|역자 조유근, 고건, 김영찬|홍릉과학출판사 |2013.02.15

  
