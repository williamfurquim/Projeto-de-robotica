#ifndef INDEX_H
#define INDEX_H

const char MAIN_PAGE[] = R"rawliteral(

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Controle Robótico</title>

    <style>
        @import url('https://fonts.googleapis.com/css2?family=Figtree&display=swap');
        
        * { 
            padding: 0; 
            margin: 0; 
            box-sizing: border-box; 
            font-family: 'Figtree', sans-serif; 
        }

        body { 
            background: linear-gradient(90deg,rgba(2, 0, 36, 1) 0%, rgba(9, 9, 121, 1) 21%, rgba(26, 81, 232, 1) 57%); 
            color: rgb(219, 217, 217); 
            min-height: 90vh; 
        }

        main { 
            max-width: 900px; 
            margin: 30px auto; 
            padding: 20px; 
        }

        h2 { 
            font-size: 58px; 
            font-weight: bold; 
            text-shadow: 1px 3px 3px black; 
            text-align: center; 
            margin-bottom: 40px; 
        }

        h3 { 
            text-align: center; 
            margin-top: 30px; 
            margin-bottom: 10px; 
        }

        .grid { 
            display: grid; grid-template-columns: repeat(auto-fit, minmax(200px, 1fr)); 
            gap: 10px; 
            justify-items: center; 
        }

        button { 
            padding: 16px 40px; 
            border-radius: 10px; 
            border: none; 
            cursor: pointer; 
            font-weight: bold; 
            transition: 0.3s; 
            font-size: 20px; 
        }

        button:hover { 
            transform: scale(1.1); 
            box-shadow: 0px 0px 10px rgb(0, 0, 0); 
        }

        .btn-on { 
            background-color: #EBEBEB; 
            color: #2B2B2B; 
        }

        .btn-off { 
            background-color: #000000; 
            color: white;
        }

        .btn-auto { 
            background-color: #ff9800; 
            color: black; 
            margin-top: 35px; 
        }

        a { 
            text-decoration: none; 
            display: flex; 
            flex-direction: column; 
            align-items: center; 
            margin-bottom: 10px; 
        }

        .btn-text { 
            color: rgb(219, 217, 217); 
            font-weight: bold; 
            font-size: 22px; 
            margin-bottom: 5px; 
            text-shadow: 1px 3px 5px black; 
        }

        .sensores { 
            display: grid; grid-template-columns: repeat(2, 1fr); 
            gap: 10px; 
            margin: 20px auto; 
            max-width: 600px; 
        }

        .sensor {
            background: #444; 
            padding: 12px; 
            border-radius: 8px; 
            text-align: center; 
            font-weight: bold;
            transition: background 0.3s;
            box-shadow: inset 0 0 5px black; 
        }

        .sensor.ativo { 
            background: #4CAF50; 
            color: white; 
            box-shadow: 0 0 10px #4CAF50; 
        }
        
        .titulo-baixo {
            margin-top: 70px; 
            margin-bottom: 40px;
        }

        footer {
            background: linear-gradient(90deg,rgba(2, 0, 36, 1) 0%, rgb(5, 5, 68) 21%, rgb(17, 52, 148) 57%);
            color: white;
            text-shadow: 2px 2px 3px black;
            font-size: 22px;
            display: flex;
            height: 80px;
            width: 100%;
            align-items: center;
            justify-content: space-around;
        }
    </style>
</head>

<body>
    <main>

        <h2>Sensores em Tempo Real</h2>
        <div class='sensores'>
        <div class='sensor' id='ED1'>MAGAZINE RECUADO</div>
        <div class='sensor' id='ED2'>MAGAZINE AVANÇADO</div>
        <div class='sensor' id='ED4'>ROTATOR AVANÇADO</div>
        <div class='sensor' id='ED5'>ROTATOR RECUADO</div>
        <div class='sensor' id='ED6'>SENSOR DE BARREIRA</div>                   
        <div class='sensor' id='ED3'>PRESSOSTATO</div>           
        <div class='sensor' id='ED0'>ENTRADA D26</div> 
        <div class='sensor' id='ED7'>ENTRADA D27</div>
        </div>

        <h2 class="titulo-baixo">Controle a Máquina</h2>
        <div class='grid'>
        <!-- OS BOTÕES SERÃO INSERIDOS DINAMICAMENTE PELO CÓDIGO C++ -->
        )rawliteral";
        const char HTML_FIM[] = R"rawliteral(
        </div>

        <div style='text-align:center;'>
            <a href='/processo'><button class='btn-auto'>Processo Automático</button></a>
            <a href='/tempo'><button class='btn-auto'>Exibir Histórico</button></a>
        </div>

    </main>

    <footer><p>William Furquim e Amanda Jaguella</p></footer>

    <script>
        function atualizarSensores() {
            fetch('/status')
                .then(res => res.json())
                .then(data => {
                for (let i = 0; i < 8; i++) {
                    const div = document.getElementById('ED' + i);
                    if (data['ED' + i]) {
                    div.classList.add('ativo');
                    } else {
                    div.classList.remove('ativo');
                    }
                }});
        }

        setInterval(atualizarSensores, 500);
    </script>

</body>
</html>
)rawliteral";

#endif