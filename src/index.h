#ifndef INDEX_H
#define INDEX_H

const char MAIN_PAGE[] = R"rawliteral(

<!DOCTYPE html>
<html lang="pt-br">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" type="image/png" href="data:image/png;base64,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">
<title>Controle Robótico</title>
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Figtree&display=swap');
        
        *{ 
        padding: 0; 
        margin: 0; 
        box-sizing: border-box; 
        font-family: 'Figtree', sans-serif; 
        }

        body{ 
        background: linear-gradient(90deg,rgba(2, 0, 36, 1) 0%, rgba(9, 9, 121, 1) 21%, rgba(26, 81, 232, 1) 57%); 
        color: rgb(219, 217, 217); 
        min-height: 90vh; 
        }

        main{ 
        max-width: 900px; 
        margin: 30px auto; 
        padding: 20px; 
        }

        h2{ 
        font-size: 58px; 
        font-weight: bold; 
        text-shadow: 1px 3px 3px black; 
        text-align: center; 
        margin-bottom: 40px; 
        }

        h3{ text-align: center; 
        margin-top: 30px; 
        margin-bottom: 10px; 
        }

        .grid{ 
        display: grid; grid-template-columns: repeat(auto-fit, minmax(200px, 1fr)); 
        gap: 10px; 
        justify-items: center; 
        }

        button{ 
        padding: 16px 40px; 
        border-radius: 10px; 
        border: none; 
        cursor: pointer; 
        font-weight: bold; 
        transition: 0.3s; 
        font-size: 20px; 
        }

        button:hover{ 
        transform: scale(1.1); 
        box-shadow: 0px 0px 10px rgb(0, 0, 0); 
        }

        .btn-on{ 
        background-color: #EBEBEB; 
        color: #2B2B2B; 
        }

        .btn-off{ 
        background-color: #000000; 
        color: white;
        }

        .btn-auto{ 
        background-color: #ff9800; 
        color: black; 
        margin-top: 35px; 
        }

        a{ 
        text-decoration: none; 
        display: flex; 
        flex-direction: column; 
        align-items: center; 
        margin-bottom: 10px; 
        }

        .btn-text{ 
        color: rgb(219, 217, 217); 
        font-weight: bold; 
        font-size: 22px; 
        margin-bottom: 5px; 
        text-shadow: 1px 3px 5px black; 
        }

        .sensores{ 
        display: grid; grid-template-columns: repeat(2, 1fr); 
        gap: 10px; 
        margin: 20px auto; 
        max-width: 600px; 
        }

        .sensor{
        background: #444; 
        padding: 12px; 
        border-radius: 8px; 
        text-align: center; 
        font-weight: bold;
        transition: background 0.3s;
        box-shadow: inset 0 0 5px black; 
        }

        .sensor.ativo{ 
        background: #4CAF50; 
        color: white; 
        box-shadow: 0 0 10px #4CAF50; 
        }
        
        .titulo-baixo{
        margin-top: 70px; 
        margin-bottom: 40px;
        }

        footer{
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
    <footer><p>William Furquim, Amanda Jaguella e Emilly Nascimento</p></footer>


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
        }
        });
    }
    setInterval(atualizarSensores, 500);
    </script>

</body>
</html>
)rawliteral";

#endif