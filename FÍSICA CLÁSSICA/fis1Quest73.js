let input = require('fs').readFileSync('stdin', 'utf-8');
let lines = input.split('\n');

let arrayX0 = lines.shift().split(' ');
let arrayV0 = lines.shift().split(' ');

const converteEntradasSI = _ => {
    arrayX0 = arrayX0.map(element => parseFloat(element / 100).toPrecision(2));
    arrayV0 = arrayV0.map(element => parseFloat(element / 100).toPrecision(2));
}
converteEntradasSI();

const imprimeEntradas = _ => {
    console.log('Array X0 (em metros):');
    console.log(arrayX0);

    console.log('Array V0 (metros por segundo [m/s]):');
    console.log(arrayV0);
}
imprimeEntradas();

class FrequenciaAngular {
    constructor(constanteElastica, massa) {
        this.constanteElastica = constanteElastica;
        this.massa = (massa / 1000);
    }

    get frequenciaAngular() {
        return this.calculaFrequenciaAngular();
    }

    calculaFrequenciaAngular() {
        return Math.sqrt(this.constanteElastica / this.massa).toPrecision(2);
    }

    imprime() {
        console.log(`Constante Elástica: ${this.constanteElastica} [n/m] (newton por metros)`);
        console.log(`Massa: ${this.massa} kg`);
        console.log(`Frequência angular: ${this.frequenciaAngular} hertz`);
    }
}

class Amplitude {
    constructor() {
        this.arrayAmplitude = [];
    }

    calculaAmplitude(arrayX0, arrayV0, frequenciaAngular) {
        const callBack = (elementoArrayX0, i) => {
            let amplitude = (elementoArrayX0 ** 2) + (arrayV0[i] ** 2);
            amplitude = Math.sqrt(amplitude / (frequenciaAngular ** 2)).toPrecision(2);

            return this.arrayAmplitude.push(amplitude);
        };

        arrayX0.forEach(callBack);
    }

    imprime() {
        console.log('Array de Amplitudes (em metros):');
        console.log(this.arrayAmplitude);
    }
}

class FaseMovimentoHarmonicoSimples {
    constructor() {
        this.arrayFaseMovimentoHarmonicoSimples = [];
    }

    calculaFaseMovimentoHarmonicoSimples(arrayX0, arrayV0, frequenciaAngular) {
        const callBack = (elementoArrayV0, i) => {
            let faseMovimentoHarmonicoSimples = 0;

            const verificaSinal = _ => {
                if (arrayX0[i] == 0) {
                    (elementoArrayV0 < 0) ? faseMovimentoHarmonicoSimples -= 90 : faseMovimentoHarmonicoSimples += 90;
                } else {
                    const toDegree = angle => angle * (180 / Math.PI);

                    faseMovimentoHarmonicoSimples = Math.atan(-elementoArrayV0 / (frequenciaAngular * arrayX0[i]));
                    faseMovimentoHarmonicoSimples = toDegree(faseMovimentoHarmonicoSimples);

                    const cosFaseMovimentoHarmonicoSimples = Math.cos(faseMovimentoHarmonicoSimples) >= 0;
                    const cosX0 = Math.cos(arrayX0) >= 0;

                    const sinFaseMovimentoHarmonicoSimples = Math.sin(faseMovimentoHarmonicoSimples) >= 0;
                    const sinV0 = Math.sin(elementoArrayV0) >= 0;

                    const comparaCos = (cosFaseMovimentoHarmonicoSimples == cosX0) ? true : false;
                    const comparaSin = (sinFaseMovimentoHarmonicoSimples == sinV0) ? true : false;

                    const comparaCosSin = (comparaCos && comparaSin) ? true : false;

                    if (comparaCosSin == false) {
                        faseMovimentoHarmonicoSimples += 180;
                    }
                }

                return faseMovimentoHarmonicoSimples.toPrecision(3).concat('°');
            }

            faseMovimentoHarmonicoSimples = verificaSinal(arrayX0, arrayV0);

            this.arrayFaseMovimentoHarmonicoSimples.push(faseMovimentoHarmonicoSimples);
        }

        arrayV0.forEach(callBack);

        return this.arrayFaseMovimentoHarmonicoSimples;
    }

    imprime() {
        console.log('Array de Fases do Movimento Harmônico Simples:');
        console.log(this.arrayFaseMovimentoHarmonicoSimples);
    }
}

fa = new FrequenciaAngular(200, 250);
fa.frequenciaAngular;
fa.imprime();

a = new Amplitude();
a.calculaAmplitude(arrayX0, arrayV0, fa.frequenciaAngular);
a.imprime();

fm = new FaseMovimentoHarmonicoSimples();
fm.calculaFaseMovimentoHarmonicoSimples(arrayX0, arrayV0, fa.frequenciaAngular);
fm.imprime();