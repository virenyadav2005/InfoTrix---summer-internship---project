<?php
header('Location: http://localhost/groupproject.html');
include("project_response.php");
//include("form.html");
if(isset($_POST['submit'])){
    //if(!empty($_POST['name']) && !empty($_POST['EMAIL']) && !empty($_POST['NEMBER']) && !empty($_POST['CITY']) && !empty($_POST['PIN']) && !empty($_POST['feed'])){
$name=$_POST['name'];
$email=$_POST['EMAIL'];
$number=$_POST['NUMBER'];
$city=$_POST['CITY'];
$pin=$_POST['PIN'];
$feed=$_POST['feed'];

$sql = "INSERT INTO `feedback`(`NAME`, `E-MAIL`, `PHONE NUMBER`, `CITY`, `PINCODE`, `FEEDBACK`) VALUES ('$name','$email','$number','$city','$pin','$feed')";
$result=mysqli_query($conn,$sql) or die(mysqli_error());
if($result){
    echo "form submitted";
}
/*else{
    echo "form not submitted";
}*/
}
/*else{
    echo "all fields required";
}*/

//}

?>