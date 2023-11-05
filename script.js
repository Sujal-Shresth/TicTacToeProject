var winCombo = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
]

var xCombo = [];
var oCombo = [];
var count = 0;
var gameOver = false;

const resultMessage = document.getElementById("newGame");
const gameResult = document.getElementById("result");
const restart = document.getElementById("button");

document.addEventListener('click', e => {
    if(e.target.classList.contains('tableBox')){
        if(e.target.innerHTML == ""){
            var indx =e.target.getAttribute('id');
        if(count%2 == 0){
            xCombo.push(indx-1);
            console.log(xCombo);
            e.target.innerHTML = "X";
            result(winCombo,xCombo,"X");
        }

        else{
            oCombo.push(indx-1);
            console.log(xCombo);
            e.target.innerHTML = "O";
            result(winCombo,oCombo,"O");
        }

        count++;
        }

        if(count == 9 && gameOver == false){
            resultMessage.style.display="flex";
            gameResult.innerHTML = "It's a tie 🤝 ";
        }
    }
})


function result(winCombo, combo, player){
    for(let i = 0; i < winCombo.length; i++){
        let attemptCounter = 0;
        let attempts = [];
        for(let j = 0; j < winCombo[i].length; j++){
            if(combo.includes(winCombo[i][j])){
                attempts.push(true);
                attemptCounter++;
            }
            else{
                attempts.push(false);
            }
            if(attemptCounter > 2){
                if(attempts.every(check => check === true)){
                    gameOver = true;
                    resultMessage.style.display="flex";
                    gameResult.innerHTML = '"'+ player +'"' + ' Won the game!'; 
                }
            }
        }  
    }  
}

restart.onclick=()=>{
    history.go(0);
}