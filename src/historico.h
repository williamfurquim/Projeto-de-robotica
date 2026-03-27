#ifndef HISTORICO_H
#define HISTORICO_H

const char HISTORICO_HTML_INICIO[] = R"rawliteral(

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Histórico de Processos</title>

    <style>       
        body { 
            font-family: sans-serif; 
            background: #1e1e2f; 
            color: white; 
            text-align: center; 
            padding-top: 20px;
        }

        h1 { 
            font-size: 26px;
            margin-bottom: 20px; 
        }

        div.log { 
            margin-top: 10px; 
            font-size: 18px; 
            line-height: 1.6; 
            text-align: left; 
            max-width: 500px; 
            margin-inline: auto; 
            background: #333; 
            padding: 20px; 
            border-radius: 10px; 
        }

        a { 
            display: inline-block; 
            margin-top: 20px; 
            background: #ff9800; 
            padding: 10px 20px; 
            border-radius: 10px; 
            text-decoration: none; 
            color: black; 
            font-weight: bold; 
        }
    </style>
</head>

    <body>
        <h1>Histórico de Processos Automáticos</h1>

        <div class='log'>
        )rawliteral";

        const char HISTORICO_HTML_FIM[] = R"rawliteral(
        </div>
        
        <a href='/'>Voltar ao menu principal</a>
    </body>
</html>
)rawliteral";

#endif