#ifndef PROCESSO_H
#define PROCESSO_H

const char PROCESSO_HTML[] = R"rawliteral(

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Processo automático</title>

    <style>
        body { 
            font-family: sans-serif; 
            background: #1e1e2f; 
            color: white; 
            text-align: center; 
            padding-top: 40px; 
        }

        h1 {
            
        }

        #statusProcesso {
            margin-top: 30px; 
            font-size: 24px; 
            font-weight: bold; 
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
    </style>
</head>

<body>
    <h1>Executando processo automático...</h1>
    <div id='statusProcesso'>Iniciando...</div>

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