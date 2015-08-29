# 함수설계

## addStudent()
```
1. 함수명 : addStudent
2. 기  능 : 학생정보를 추가한다.
3. 출  력 : students
4. 입  력 : students
5. 자료명세서 :
```
번호 | 명칭 | 자료유형 | 구분 | 비고
-----|-----|-----|-----|-----|
1 | students | StudentInformation (list) | 준비 |
2 | studentInfo | StudentInformation | 처리 |
3 | name | String | 처리 |
4 | phone | String | 처리 |
5 | address | String | 처리 |
```
6. 처리과정
    1. 성명, 전화번호, 주소, 반, 과목들, 과목점수들을 입력받는다.
    2. 학생들에 입력받는 정보를 추가한다.
    3. 끝내다.
7. 검토
```

## removeStudent()
```
1. 함수명 : removeStudent
2. 기  능 : 학생정보를 삭제한다.
3. 출  력 : students
4. 입  력 : students, name
5. 자료명세서 :
```
번호 | 명칭 | 자료유형 | 구분 | 비고
-----|-----|-----|-----|-----|
1 | students | StudentInformation | 준비 |
2 | name | String | 처리 |
```
6. 처리과정
    1. 성명을 입력받는다.
    2. 학생들에서 입력받은 성명을 찾는다.
        2.1. 찾으면, 학생정보를 삭제한다.
    3. 끝내다.
7. 검토
```

## editStudent()
```
1. 함수명 : editStudent
2. 기  능 : 학생정보를 수정한다.
3. 출  력 : students
4. 입  력 : students, name
5. 자료명세서 :
```
번호 | 명칭 | 자료유형 | 구분 | 비고
-----|-----|-----|-----|-----|
1 | students | StudentInformation | 준비 |
2 | name | String | 처리 |
3 | phone | String | 처리 |
4 | address | String | 처리 |
5 |
```
6. 처리과정
    1. 성명을 입력받는다.
    2. 학생들에서 입력받은 성명의 학생을 찾는다.
        2.1. 찾으면, 전화번호, 주소, 반, 국어점수, 영어점수, 수학점수를 입력받는다.
        2.2. 입력받는 학생정보를 저장한다.
    3. 끝내다.
7. 검토
```

## searchStudent()
```
1. 함수명 : searchStudent
2. 기  능 : 학생을 찾는다.
3. 출  력 : student
4. 입  력 : students, name
5. 자료명세서 :
```
번호 | 명칭 | 자료유형 | 구분 | 비고
-----|-----|-----|-----|-----|
1 | students | StudentInformation | 준비 |
2 | name | String | 처리 |
```
6. 처리과정
    1. 성명을 입력받는다.
    2. 학생들에서 입력받은 학생을 찾는다.
        2.1. 찾으면 찾은 학생을 출력한다.
    3. 끝내다.
7. 검토
```

## load()
```
1. 함수명 : load
2. 기  능 : 파일에서 학생정보들을 불러온다.
3. 출  력 : students
4. 입  력 : students
5. 자료명세서 :
```
번호 | 명칭 | 자료유형 | 구분 | 비고
-----|-----|-----|-----|-----|
1 | students | StudentInformation | 준비 |
2 | student | StudentInformation | 처리 |
3 | i | Integer | 추가 |
4 | name | String | 처리 |
5 | phone | String | 처리 |
6 | address | String | 처리 |
7 | koreanScore | Integer | 처리 |
8 | englishScore | Integer | 처리 |
9 | mathematics | Integer | 처리 |
10 | classNumber | Integer | 처리 |
11 | totalScore | Integer | 처리 |
12 | average | Float | 처리 |
13 | grade | Integer | 처리 |

```
6. 처리과정
    1. 파일의 끝이 아닌동안 반복한다.
        1.1. 성명, 전화번호, 주소, 반, 국어점수, 영어점수, 수학점수, 총점, 평균, 석차를 읽는다.
        1.2. 저장할 위치를 찾는다.
        1.3. 입력받은 정보를 학생정보에 저장한다.
    2. 끝내다.
7. 검토
```

## save()
```
1. 함수명 : save
2. 기  능 : 학생정보를 파일에 저장한다.
3. 출  력 : students
4. 입  력 : students
5. 자료명세서 :
```
번호 | 명칭 | 자료유형 | 구분 | 비고
-----|-----|-----|-----|-----|
1 | students | StudentInformation | 준비 |
2 | student | StudentInformation | 처리 |
3 | i | Integer | 추가 |
4 | name | String | 처리 |
5 | phone | String | 처리 |
6 | address | String | 처리 |
7 | koreanScore | Integer | 처리 |
8 | englishScore | Integer | 처리 |
9 | mathematics | Integer | 처리 |
10 | classNumber | Integer | 처리 |
11 | totalScore | Integer | 처리 |
12 | average | Float | 처리 |
13 | grade | Integer | 처리 |
```
6. 처리과정
    1. 학생들 수만큼 반복한다.
        1.1. 파일에 성명, 전화번호, 주소, 반, 국어점수, 영어점수, 수학점수, 총점, 평균, 석차를 쓴다.
    2. 끝내다.
7. 검토
```

## main()
```
1. 함수명 : main
2. 기  능 : menu 화면을 출력하고 사용자 입력받아 해당 menu를 실행한다.
3. 출  력 : x
4. 입  력 : x
5. 자료명세서 :
```
번호 | 명칭 | 자료유형 | 구분 | 비고
-----|-----|-----|-----|-----|
1 | students | StudentInformation | 준비 |
2 | menu | Integer | 입력 |
```
6. 처리과정
    1. 메뉴를 출력한다.
    2. 사용자로부터 메뉴를 입력받는다.
    3. 해당 메뉴를 실행한다.
    4. 끝내다.
7. 검토
```