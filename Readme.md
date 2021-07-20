# [미션] 리눅스 설치

### 리눅스 설치

1. 각자 컴퓨터 환경에서 사용할 수 있는 가상 환경(Virtual Machine)에서 리눅스 운영체제를 설치한다.

    - 권장 설치 운영체제 : 권장버전 ubuntu 20.04 (18.04도 가능함)
    
    1) virtualBox를 설치합니다
    
        <p>
            <img width="891" alt="스크린샷 2021-07-20 오후 12 27 44" src="https://user-images.githubusercontent.com/48857296/126257510-c9551384-f338-41b9-aa2c-8d908286936b.png">
        </p>
    
    2) 우분투를 LTS 버전으로 다운 후 VirtualBox에 가상 머신을 다음 사진과 같이 만든다
    
        - 계속을 눌러 설치를 진행합니다
        
        <p>
            <img width="891" alt="스크린샷 2021-07-20 오후 2 12 00" src="https://user-images.githubusercontent.com/48857296/126265466-8ae414f3-081e-4684-a9b9-6caa5a14d448.png">
        </p>
    
    3) 가상머신에 우분투 설치하기
    
        - 가상머신의 저장소의 광학 드라이브를 다운한 우분트 이미지로 선택해줍니다
    
        <p>
            <img width="893" alt="가상머신에 우분트 설치" src="https://user-images.githubusercontent.com/48857296/126265772-f0cffa8e-67f6-45b1-87a5-6708c6856fff.png">
        </p>
    
    4) 시작을 누르고 우분투를 마저 설치하면 된다
    
        - 시작을 눌렀을 때 맥의 경우 보안 문제로 에러가 날 수 있는데 "kernel driver not installed" 에러의 경우 참고 사이트와 같이 해결 바란다
            
            - [참고](https://medium.com/@Aenon/mac-virtualbox-kernel-driver-error-df39e7e10cd8)
            
        - 화면 크기가 작을 경우 가상환경 설정에 들어가서 디스플레이의 크기 조정 비율을 높이면 된다

    5) 완료
    
        <p>
            <img width="787" alt="설치 완료" src="https://user-images.githubusercontent.com/48857296/126268834-d4ec4de8-822e-4511-86bc-d71e70a78b7d.png">
        </p>


2. 가상 환경에 원격으로 접속할 수 있도록 ssh 설정을 하고, root 계정 이외에 본인 접속할 계정을 추가한다.

    - [참고](https://velog.io/@younho9/Mac-%EB%B2%84%EC%B6%94%EC%96%BC%EB%B0%95%EC%8A%A4VirtualBox%EC%97%90-%EC%84%A4%EC%B9%98%EB%90%9C-%EC%9A%B0%EB%B6%84%ED%88%ACUbuntu-%EB%A7%A5-%ED%84%B0%EB%AF%B8%EB%84%90%EC%97%90%EC%84%9C-%EC%A0%91%EC%86%8D%ED%95%98%EA%B8%B0)

    1) ssh 설정
    
        <p>
            <img width="900" alt="ssh설정1" src="https://user-images.githubusercontent.com/48857296/126277118-ecccf418-e2e4-44d1-900e-8de97b63603a.png">
        </p>
        
        <p>
            <img width="1307" alt="ssh설정2" src="https://user-images.githubusercontent.com/48857296/126277159-8f0d9036-b3db-4a32-984d-a42517baf79e.png">
        </p>

    2) root 계정 이외에 보인 접속할 계정을 추가
    
        - sudo adduser [아이디]로 추가한다

3. 본인 계정에 대한 패스워드를 설정한다

    <p>
        <img width="467" alt="본인계정 생성" src="https://user-images.githubusercontent.com/48857296/126277270-8ffc9291-11d1-4a6d-b99f-82981eca28d7.png">
    </p>

4. 로컬 컴퓨터에서 가상 환경 리모트 컴퓨터에 ssh로 접속해서 본인 계정으로 로그인한다.

    <p>
        <img width="1483" alt="다른 계정으로 로그인 완료" src="https://user-images.githubusercontent.com/48857296/126277550-9e3f781e-44b2-4c52-8890-6fb42bab7859.png">
    </p>

5. 본인 계정에서 /backup 디렉토리를 생성하고 764 모드로 접근 권한을 바꿔서, 본인 계정으로 /backup 경로 아래에 파일을 생성할 수 있도록 설정한다.

    <p>
        <img width="322" alt="chmod 764" src="https://user-images.githubusercontent.com/48857296/126279659-5a22ff46-c7f0-446e-a72c-47635ac5c4b9.png">
    </p>
    
6. 가상 환경에 오늘 날짜 + 서울 시간대로 지정해서 로컬과 가상 환경이 동일하도록 맞춘다.
    
    - sudo dpkg-reconfigure tzdata 를 활용하여 시간을 설정한다

7. 가상 환경에서 터미널을 열고 date 명령으로 오늘 날짜를 출력한 상태로, 화면을 캡처한다.

    <p>
        <img width="545" alt="시간" src="https://user-images.githubusercontent.com/48857296/126279809-c818d09c-e86f-4b26-8a2c-60fdf00eabde.png">
    </p>

8. 가상 환경에 node.js v14.x를 설치하고 버전을 확인한다.

    <p>
        <img width="264" alt="nodejs 버젼" src="https://user-images.githubusercontent.com/48857296/126281960-72c660d4-f83a-4119-a901-7bdbe74593c6.png">
    </p>

9. 어제 작성한 day1 미션 js파일을 복사해서 실행한다.

    <p>
        <img width="785" alt="nodejs" src="https://user-images.githubusercontent.com/48857296/126281410-2743b6fe-18a9-4a1d-a559-728e3ff8bb14.png">
    </p>


# [미션] 셸스크립트 자동화

### 가상환경 요구사항

1. 다음과 같은 동작을 하기 위해서 bash 쉘 스크립트를 작성한다.

    - /backup 경로 아래에 오늘 날짜로 20210625 형식으로 하위 디렉토리를 생성한다. 만약 이미 디렉토리가 있으면 무시한다.

    - 하위 디렉토리에 /var/log/syslog와 /var/log/dmesg 파일을 log_20210625-1300.zip 형태로 압축하는 쉘 스크립트를 구현한다.

    - 파일 이름은 log_{YYYYMMDD}-{hhmm}.zip 형태로 중간에 년월일-시분을 포함해야 한다.

2. crontab 동작 방식을 확인하고 아래 조건을 설정한다.

    - 위에 작성한 스크립트가 매 5분마다 (정각, 5분, 10분, ... 50분, 55분)마다 실행하도록 자동화한다.
    
    - 매시각 29분과 59분에는 /var/log/syslog 파일을 /var/log/syslog_1로 복사한다. 만약 기존에 syslog_1 파일이 있는 경우는 기존 파일을 지우고 복사한다.

### 로컬 환경 요구사항

1. 로컬 환경에서도 bash 쉘 스크립트를 작성한다.

    - 
