let display = document.getElementById('display');
let expression = '';

function appendValue(value) {
    expression += value;
    display.value = expression;
}

function clearDisplay() {
    expression = '';
    display.value = '';
}

function deleteLastCharacter() {
    expression = expression.slice(0, -1);
    display.value = expression;
}

function calculateResult() {
    try {
        expression = eval(expression);
        display.value = expression;
    } catch (error) {
        display.value = 'Error';
    }
}
