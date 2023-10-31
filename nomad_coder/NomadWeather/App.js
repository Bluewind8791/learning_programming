import React, {useEffect, useState} from 'react';
import {
  ActivityIndicator,
  Dimensions, Image,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  View,
} from 'react-native';

import * as Location from 'expo-location';
import { Fontisto } from '@expo/vector-icons';



const SCREEN_WIDTH = Dimensions.get('window').width;
const WEATHER_API_KEY = '618335e9dadc22acfc9975918330b8fb';
const icons = {
  "Clouds" : "cloudy",
  "Clear" : "day-sunny",
  "Rain" : "rain",
  "Thunderstorm" : "lightning",
  "Snow" : "snow",
  "Haze" : "day-haze",
  "Fog" : "fog",
  "Drizzle" : "fog",
  "Mist" : "fog",
  "Smoke" : "fog",
  "Dust" : "fog",
  "Sand" : "fog",
  "Ash" : "fog",
  "Squall" : "fog",
  "Tornado" : "fog",
};

function App() {
  const [city, setCity] = useState("Loading ...");
  const [isGranted, setIsGranted] = useState(true);
  const [info, setInfo] = useState(null);

  const getWeather = async () => {
    const {granted} = await Location.requestForegroundPermissionsAsync();
    if (!granted) {
      setIsGranted(false);
    }

    const {coords: {latitude, longitude}} = await Location.getCurrentPositionAsync({accuracy: 5});
    const location = await Location.reverseGeocodeAsync(
        {latitude, longitude},
        {useGoogleMaps: false}
    );
    setCity(location[0].city);

    await fetch(`https://api.openweathermap.org/data/2.5/weather?lat=${latitude}&lon=${longitude}&appid=${WEATHER_API_KEY}&units=metric`)
        .then(res => res.json())
        .then(data => setInfo(data))
    ;
  };


  useEffect(() => {
    getWeather().then();
  }, []);

  return (
    <View style={styles.container}>
      <StatusBar barStyle={'default'} />
      <View style={styles.city}>
        <Text style={styles.cityName}>{city}</Text>
      </View>
      <ScrollView contentContainerStyle={styles.weather}
                  horizontal={true}
                  pagingEnabled={true}
                  showsHorizontalScrollIndicator={false}
      >
        {!info || info.length === 0 ? (
            <View style={styles.day}>
              <ActivityIndicator size={70} color={"white"}
                                 style={{...styles.day, alignItems: "center"}}
              />
            </View>
        ) : (
            <View style={{...styles.day, paddingHorizontal: 30}}>
              <View style={styles.main}>
                <Text style={styles.degree}>{Math.round(info.main.temp)}</Text>
                <Fontisto name={icons[info.weather[0].main]} size={32} style={{marginLeft: 10}} />
              </View>
              <Text style={styles.description}>{info.weather[0].main}</Text>
            </View>
        )}
      </ScrollView>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "orange"
  },
  city: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center",
  },
  cityName: {
    color: "black",
    fontSize: 28,
    fontWeight: "900",
  },
  weather: {
    // scroll view
  },
  day: {
    // 해당 컴포넌트 사이즈가 기기의 사이즈와 동일하게 되어야 한다
    width: SCREEN_WIDTH,
    alignItems: "flex-start",
  },
  degree: {
    // flex: 4,
    color: "black",
    fontSize: 158,
    fontWeight: "900",
    marginTop: 50,
  },
  description: {
    color: "black",
    fontSize: 38,
    marginTop: -30,
  },
  main: {
    flexDirection: "row",
    alignItems: "center",
    width: "100%",
    // justifyContent: "space-between",
  },
});

export default App;

// View component는 기본적으로 flex container(display: flex)이며
// web에선 flex direction의 default 값이 row였던 반면에
// react native 에서는 column이 default 값이다

// 모바일 기기는 스크린 사이즈가 굉장히 다양하기 때문에
// 반응형 디자인을 고려해야 하기 때문에
// 대부분은 width, height를 사용하지 않고 flex size를 사용한다