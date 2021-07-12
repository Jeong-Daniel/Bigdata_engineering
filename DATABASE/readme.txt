[0] 파일은 utf-8 로 잘 맞추셔야지 글자가 깨지지 않습니다.

[1] RIMARY KEY와 AUTO_INCREMENT를 지정하지 않았을때, 기존에 MOVIE 테이블 지우고 생성

CREATE TABLE MOVIE (
  id int(2) NOT NULL,
  title varchar(100) NOT NULL,
  genre varchar(10) NOT NULL,
  myear varchar(20) NOT NULL,
  price int(2) NOT NULL,
  photo varchar(255) NOT NULL
); 

INSERT INTO MOVIE (id, title, genre, myear, price, photo) VALUES
(1, 'cccc', '드라마', '2020-06-04', 10000, './photo/라라랜드.jpg'),
(2, 'aaaa', '액션', '2020-07-07', 330000, './photo/벤허.png'),
(3, 'dddd', '액션', '2020-06-11', 20000, './photo/쿵푸팬더.jpg'), 
(4, 'bbbb', '드라마', '2020-06-08', 10000, './photo/타이타닉.jpg');



[2] RIMARY KEY와 AUTO_INCREMENT를 지정했을 때, 기존에 MOVIE 테이블 지우고 생성

CREATE TABLE MOVIE (
  id int(2) NOT NULL,
  title varchar(100) NOT NULL AUTO_INCREMENT,
  genre varchar(10) NOT NULL,
  myear varchar(20) NOT NULL,
  price int(2) NOT NULL,
  photo varchar(255) NOT NULL,
  RIMARY KEY (id)
); 

INSERT INTO MOVIE (id, title, genre, myear, price, photo) VALUES
('cccc', '드라마', '2020-06-04', 10000, './photo/라라랜드.jpg'),
('aaaa', '액션', '2020-07-07', 30000, './photo/벤허.png'),
('dddd', '액션', '2020-06-11', 20000, './photo/쿵푸팬더.jpg'), 
('bbbb', '드라마', '2020-06-08', 10000, './photo/타이타닉.jpg');


[3] 예약 테이블
CREATE TABLE Reservation (
  movie_id int(3) NOT NULL AUTO_INCREMENT,
  r_name varchar(20) NOT NULL,
  r_date varchar(20) NOT NULL,
  r_count int(2) NOT NULL,
  PRIMARY KEY (movie_id)
) ;


[selectAll.php]

while($row = mysqli_fetch_array($result)) {    
    	$tagList = $tagList.'<li><img style="margin:11px 20px;", src="'.$row["photo"].'">';
        $tagList = $tagList.'<span class="ui-li-count"> 장르 : '.$row["genre"].'</span>';
        $tagList = $tagList.'<h2>'.$row["title"].'</h2>';
        $tagList = $tagList.'<p> 요금 : '.$row["price"].' 원</p>';         
        $tagList = $tagList.'<p> 상영날짜 : '.$row["myear"].'</p>';   
		$tagList = $tagList.'<p> <a href="reservation.php?movie_id='.$row["id"].'"><img src="http://swedu2.dothome.co.kr/img/rs.png"></a> </p> 	</li>';   
}


[reservation.php]
<?
	$conn=mysqli_connect("localhost",  "아이디", "비번", "디비") or die("movieDB 접속 실패 !!");
	
	$movie_id = $_GET['movie_id'];

	$sql	= "select * from MOVIE where id = '".$movie_id."'";
	//echo $sql;
	//exit;  //일시 멈춤, 디버깅할때 유용한 명령어

	$result	= mysqli_query($conn, $sql);
	$row	= mysqli_fetch_array($result);
	$title	= $row['title'];  // * 모든 필드에서 title 필드 가져오기 의미
	
	mysqli_close($conn);
?> 
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8"/>
	<meta name="viewport" content="initial-scale=1.0, width=device-width">
	<title>예약하기</title>
    <!-- 제이쿼리 모바일, 제이쿼리 라이브러리 화일 -->
	<link rel="stylesheet" href="http://code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.css"/>
	<script src="http://code.jquery.com/jquery-1.11.1.min.js"></script>
	<script src="http://code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.js"></script>	
</head>  
<body>
  <div data-role="page" id="id">
	<div data-role="content">
		<form name="form1" method="post" enctype="multipart/form-data" action="reservation_result.php" data-ajax="false">  
			<h3>영화제목 : <?=$title?><br><br>
				영화번호 
				<input type="text" name="movie_id" value="<?=$movie_id?>" data-mini="true">
				예약자
				<input type="text" name="r_name" value="" data-mini="true">
			


~~~~~~~~~~~~