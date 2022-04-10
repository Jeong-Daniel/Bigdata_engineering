[0] ������ utf-8 �� �� ���߼ž��� ���ڰ� ������ �ʽ��ϴ�.

[1] RIMARY KEY�� AUTO_INCREMENT�� �������� �ʾ�����, ������ MOVIE ���̺� ����� ����

CREATE TABLE MOVIE (
  id int(2) NOT NULL,
  title varchar(100) NOT NULL,
  genre varchar(10) NOT NULL,
  myear varchar(20) NOT NULL,
  price int(2) NOT NULL,
  photo varchar(255) NOT NULL
); 

INSERT INTO MOVIE (id, title, genre, myear, price, photo) VALUES
(1, 'cccc', '���', '2020-06-04', 10000, './photo/��󷣵�.jpg'),
(2, 'aaaa', '�׼�', '2020-07-07', 330000, './photo/����.png'),
(3, 'dddd', '�׼�', '2020-06-11', 20000, './photo/��Ǫ�Ҵ�.jpg'), 
(4, 'bbbb', '���', '2020-06-08', 10000, './photo/Ÿ��Ÿ��.jpg');



[2] RIMARY KEY�� AUTO_INCREMENT�� �������� ��, ������ MOVIE ���̺� ����� ����

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
('cccc', '���', '2020-06-04', 10000, './photo/��󷣵�.jpg'),
('aaaa', '�׼�', '2020-07-07', 30000, './photo/����.png'),
('dddd', '�׼�', '2020-06-11', 20000, './photo/��Ǫ�Ҵ�.jpg'), 
('bbbb', '���', '2020-06-08', 10000, './photo/Ÿ��Ÿ��.jpg');


[3] ���� ���̺�
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
        $tagList = $tagList.'<span class="ui-li-count"> �帣 : '.$row["genre"].'</span>';
        $tagList = $tagList.'<h2>'.$row["title"].'</h2>';
        $tagList = $tagList.'<p> ��� : '.$row["price"].' ��</p>';         
        $tagList = $tagList.'<p> �󿵳�¥ : '.$row["myear"].'</p>';   
		$tagList = $tagList.'<p> <a href="reservation.php?movie_id='.$row["id"].'"><img src="http://swedu2.dothome.co.kr/img/rs.png"></a> </p> 	</li>';   
}


[reservation.php]
<?
	$conn=mysqli_connect("localhost",  "���̵�", "���", "���") or die("movieDB ���� ���� !!");
	
	$movie_id = $_GET['movie_id'];

	$sql	= "select * from MOVIE where id = '".$movie_id."'";
	//echo $sql;
	//exit;  //�Ͻ� ����, ������Ҷ� ������ ��ɾ�

	$result	= mysqli_query($conn, $sql);
	$row	= mysqli_fetch_array($result);
	$title	= $row['title'];  // * ��� �ʵ忡�� title �ʵ� �������� �ǹ�
	
	mysqli_close($conn);
?> 
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8"/>
	<meta name="viewport" content="initial-scale=1.0, width=device-width">
	<title>�����ϱ�</title>
    <!-- �������� �����, �������� ���̺귯�� ȭ�� -->
	<link rel="stylesheet" href="http://code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.css"/>
	<script src="http://code.jquery.com/jquery-1.11.1.min.js"></script>
	<script src="http://code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.js"></script>	
</head>  
<body>
  <div data-role="page" id="id">
	<div data-role="content">
		<form name="form1" method="post" enctype="multipart/form-data" action="reservation_result.php" data-ajax="false">  
			<h3>��ȭ���� : <?=$title?><br><br>
				��ȭ��ȣ 
				<input type="text" name="movie_id" value="<?=$movie_id?>" data-mini="true">
				������
				<input type="text" name="r_name" value="" data-mini="true">
			


~~~~~~~~~~~~