# student_management_program


## 개요

- 학생들의 이름, 전화번호, 학번, 성적 등의 정보가 담겨있는 txt파일을 유지/관리하고 정보의 저장이 편리한 동적 메모리를 이용해 저장

## 프로그램 구성형태

- show, add, del, exam, sort, quit 명령어를 입력받아 각 기능을 수행한다. (각 명령어 별로 함수 정의)
- student.h / student.c
  
  학생들의 정보를 구조체로 선언하고 관련 함수 선언, 정의

- exam.h / exam.c

  학생들의 시험정보를 입력하고 처리하는 함수들을 선언, 정의

- class.c
  
  main(), 명령어를 입력받고, 해석하고, 관련 함수들을 호출하는 함수들이 선언되고 정의하는 파일

## DATA

### students.txt

|students.txt|
|:--------:|
|20170501   홍길동  010-1234-5678   19980301    m   175 hong@gmail.com|
|20170502   성춘향  010-0123-4567   19990101    f   165 sung@gmail.com|

|-|-|-|
|:--------:|:-------:|:-------:|
|학번|id|8자리 코드, 중복X, 식별자로 사용|
|이름|name|한글 10자리, 영어 20자리|
|전화번호|tel|11자리 문자열 ('-'포함)|
|생년월일|birth|YYYYMMDD|
|키|height|cm|
|이메일|email|최대 30글자|

- 파일에서 각 항목은 \t으로 구분

### exam.txt

|exam.txt|
|:--------:|
|20170501   홍길동  92  94|
|20170502   성춘향  65  71|

- 시험정보는 txt파일에 직접 입력
- 파일에서 각 항목은 \t으로 구분
- 전학 간 학생의 성적도 있으며, 시험 성적이 없는 학생이 있을 수도 있다. 학생 데이터에는 있지만 성적이 없는 학생은 결시로 0점 처리

## 프로그램 실행
- visual studio - [프로젝트] - [속성] - <디버깅> 항목에서 명령인수에 필요한 정보 입력. 명령인수에 students.txt 입력하여 실행

## 기능

### 프로그램의 시작
- 실행파일이 있는 디렉토리에서 students.txt 파일을 읽어서 학생들의 정보를 가져온다.
- 파일이 없으면, 파일이 없다는 메시지와 함께 students.txt파일 생성
- 명령어를 입력받을 수 있는 프롬프트 표시
- 학생들에 대한 정보를 모두 저장하고, 삽입, 삭제 할 수 있도록 저장해야함.
- 학생 정보는 최대 20개 이상 저장할 수 있도록 저장 공간을 확보하도록 하며, 가득 차면 재할당을 통해 10개씩 추가. (malloc, realloc 이용)

### show
- 전체 학생들의 정보를 입력된 순서대로 출력

### add

- 학생 추가
- show 명령에서 새로운 학 생의 정보가 출력되어야 함

```c
>>> add

학번 : 20180509
이름 : 강교수
전화 : 010-3333-4444
생년월일 : 19990505
성 : m
키 : 175
이메일 : kang@naver.com

강교수 의 정보가 추가되었습니다.
```

### del

- 학생 정보 삭제
- 학번(id)를 이용하여 삭제
- 정보가 없을 경우 예외 처리
```c
>>> del

학번 : 20180509
강교수 의 정보가 삭제 되었습니다.
```

### exam

- 시험 결과 출력
- 학생정보가 없는 학생의 경우 무시
- 학생정보 있지만 시험정보 없는 경우 0점 처리
- 평균은 소수점 1자리 까지 출력
- 95이상 A+, 90이상 A, 85이상 B+, 80이상 B, 75이상 C+, 70이상 C, 65이상 D+, 60이상 D, 60미만 F

```c
>>> exam

학번        이름   중간 기말 평균   학점 
20170501    홍길동  92  94  93.0    A
20170502    박문수  68  73  70.5    C
20170503    성춘향  65  71  68.0    D+
20170504    향단    100 100 100.0   A+
>>>
```

### sort
- 키(height) 기준 오름차순 정렬, 동일 시 이름순 정렬
- sort 명령 다음에도 저장순서는 바뀌지 않도록 함.

```c
>>> sort

 학번    이름   전화          생년월일  성 키   이메일
20170504 강교수 010-3333-4444 19980505 f 160 kang@naver.com
20170504 향  단 010-2222-3333 19980903 f 160 dan@gmail.com
20170503 성춘향 010-1111-1111 19980213 f 165 sung@gmail.com
20170501 홍길동 010-1234-5678 19980301 m 175 hong@gmail.com
20170502 박문수 010-3423-1234 19980601 m 185 park@gmail.com
```

### quit

- 입력 시 프로그램 종료
- 종료 전, 현재 메모리에 저장되어 있는 학생 정보를 파일로 저장
- 데이터 변경이 있을 시 변경사항들을 파일로 저장.
- 동적 할당된 메모리들은 모두 free 시킨 후에 종료

```c
>>> quit

students.txt 파일로 정보를 저장하였습니다. 
종료합니다. 

계속하려면 아무키나 누르십시오.

```

## -
*.c, *.h, *.txt, *.exe 파일

