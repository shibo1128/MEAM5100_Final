const char body[] PROGMEM = R"===(
<!DOCTYPE html>
<html>
<head>
    <title>Button Style Link</title>
    <style>
        .modeButtonStyle {
            display: inline-block;
            width: 150px;
            height: 50px;
            line-height: 50px; /* Centers text vertically */
            text-align: center; /* Centers text horizontally */
            color: black;
            background-color: pink;
            text-decoration: none; /* Removes underline from the link */
            border: none;
            border-radius: 5px;
            font-size: 20px;
            cursor: pointer; /* Changes cursor to pointer on hover */
            margin: 10px; /* Optional: adds some space around the button */
        }
        /* Optional: Add a hover effect */
        .modeButtonStyle:hover {
            background-color: palevioletred;
        }

        .manualButtonStyle {
            display: inline-block;
            width: 150px;
            height: 50px;
            line-height: 50px; /* Centers text vertically */
            text-align: center; /* Centers text horizontally */
            color: black;
            background-color: blue;
            text-decoration: none; /* Removes underline from the link */
            border: none;
            border-radius: 5px;
            font-size: 20px;
            cursor: pointer; /* Changes cursor to pointer on hover */
            margin: 10px; /* Optional: adds some space around the button */
        }

    </style>
    <script>
        function showInstruction(mode) {
            var instructionText = '';
            switch(mode) {
                case 'wallFollowing':
                    instructionText = 'Instruction: The robot is now following the wall.';
                    break;
                case 'findTrophy':
                    instructionText = 'Instruction: The robot is searching for the trophy.';
                    break;
                case 'findFake':
                    instructionText = 'Instruction: The robot is identifying fake objects.';
                    break;
                case 'test':
                    instructionText = 'Instruction: Test mode is activated.';
                    break;
                case 'push':
                    instructionText = 'Instruction: Pushing police is activated.';
                    break;
                default:
                    instructionText = 'Instruction: Select a mode.';
            }
            document.getElementById('instruction').innerText = instructionText;
        }
    </script>
</head>
<body>
    <h1>MEAM5100 Final Console</h1>
    <h2>Modes</h2>
    <div id="instruction">Instruction: Select a mode.</div>
    <a href="/wall" class="modeButtonStyle" onclick="showInstruction('wallFollowing')">Wall Following</a>
    <a href="/trophy" class="modeButtonStyle" onclick="showInstruction('findTrophy')">Find Trophy</a><br>
    <a href="/fake" class="modeButtonStyle" onclick="showInstruction('findFake')">Find Fake</a>
    <a href="/test" class="modeButtonStyle" onclick="showInstruction('test')">Test</a>  
    <br>
    <a href="/push" class="modeButtonStyle" onclick="showInstruction('push')">Push Police</a>  

</body>
</html>
)===";
