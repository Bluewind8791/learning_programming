const WEATHER_API_KEY = 'donttakemyapikey';


function onGeoSucc(position) {
    const lat = position.coords.latitude;
    const lon = position.coords.longitude;

    fetch(`https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=${WEATHER_API_KEY}&units=metric`)
        .then(r => r.json())
        .then(json => setWeather(json))
        .catch(onGeoErr)
    ;
}

function onGeoErr() {
    const dummy = {
        "name" : "...",
        "main" : {"temp" : 0},
        "weather" : [{"main" : "I don't know"}],
    };
    setWeather(dummy);
}

function setWeather(info) {
    const city = document.querySelector("#weather span:first-child");
    city.innerText = info.name;
    const weather = document.querySelector("#weather span:last-child");
    weather.innerText = `${info.weather[0].main} / ${info.main.temp}`;
}

navigator.geolocation.getCurrentPosition(onGeoSucc, onGeoErr);