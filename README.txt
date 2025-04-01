MSG Package
	- 각 파트별 Custom Message 작성
	- .msg 파일 생성 후, CMakeLists.txt 파일에 가서 해당 메세지 파일 등록

Main Package
	- Global : 전역 설정, 공통 모듈, 파라미터 파일 보관
	- Control : 제어기 코드 작성
	- Parser : 센서 데이터, 경로 파일, 메세지 등 데이터 관리
	- Planning : 경로 계획 관련 코드 작성
