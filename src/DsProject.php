<!DOCTYPE html>
<html>

  <head>
    <style>
      ul{
        list-style: none;
        text-align: center;
      }
      li{
        padding: 0.5px;
        font-size: 2rem;
        color: white;
        background-color: black;
        display:block;
        margin: auto;
        width: 40%;
      }
      li a:hover{
        display: block;
        background-color: #424242;
        text-decoration: none;
        color: white;
      }
      a{
        text-decoration: none;
        color: white;
      }
      form {
        text-align: center;
        margin: 0;
        padding: 0;
      }
      body{
        font-family: sans-serif;
        font-size: 12px;
        background: #000;
        padding: 25px;
        text-align: center;

      }
      input[type=text] {
          width: 170px;
          -webkit-transition: width 0.4s ease-in-out;
          transition: width 0.4s ease-in-out;
          border: none;
          height: 70px;
          outline: none;
          border-radius: 50px;
          color: rgb(110,110,110);
          font-size: 1.6rem;
          font-weight: 200;
          text-align: center;
      }
      input[type=text]:focus {
          width: 50%;
      }
      p{
        margin-top: 5px;
        font-weight: 180;
        padding: 10px;
        margin-bottom: 1%;
        font-size: 3.5rem;
      }
      .switch {
        position: relative;
        display: inline-block;
        width: 60px;
        height: 34px;
      }

      .switch input {display:none;}

      .slider {
        position: absolute;
        cursor: pointer;
        top: 0;
        left: 0;
        right: 0;
        bottom: 0;
        background-color: #ccc;
        -webkit-transition: .4s;
        transition: .4s;
      }

      .slider:before {
        position: absolute;
        content: "";
        height: 26px;
        width: 26px;
        left: 4px;
        bottom: 4px;
        background-color: white;
        -webkit-transition: .4s;
        transition: .4s;
      }

      input:checked + .slider {
        background-color: #2196F3;
      }

      input:focus + .slider {
        box-shadow: 0 0 1px #2196F3;
      }

      input:checked + .slider:before {
        -webkit-transform: translateX(26px);
        -ms-transform: translateX(26px);
        transform: translateX(26px);
      }

      /* Rounded sliders */
      .slider.round {
        border-radius: 34px;
      }

      .slider.round:before {
        border-radius: 50%;
      }
    </style>
  </head>

  <body>
    <label class="switch">
      <input type="checkbox" id="check">
      <span class="slider round"></span>
    </label>

    <p><b style="color: white">Search:</b></p>

    <form>
    <input type="text" id="inp" placeholder="Enter word">
    <ul id="txtHint"></ul>
    </form>


    <script>

    var inp = document.getElementById("inp");
    inp.addEventListener("keyup", function(e) {
        var key = e.which || e.keyCode || 0;
        if (key === 72 && e.altKey) {
            showHint(inp.value);
        }
    });
    function showHint(str) {
      var mode= document.getElementById("check").checked;
      if (mode) {
        mode= 1;
      }
      else {
        mode = 0;
      }
        if (str.length == 0) {
            document.getElementById("txtHint").innerHTML = "";
            return;
        } else {
            var xmlhttp = new XMLHttpRequest();
            xmlhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                  var output = this.responseText.split(",");
                  for (var i = 0; i < output.length && i<10; i++) {
                    output[i] ="<li><a href=\"\">" + output[i] + "</a></li>";
                  }

                  output = output.toString();
                  output = output.split(',').join(" ");
                  document.getElementById("txtHint").innerHTML = output;
                }
            };
            xmlhttp.open("GET", "test.php?q=" + str +"&mode="+mode, true);
            xmlhttp.send();
        }
    }

    </script>
  </body>

</html>
