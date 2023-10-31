import {Alert, ScrollView, StyleSheet, Text, TextInput, TouchableOpacity, View} from 'react-native';
import {useEffect, useState} from "react";

import { StatusBar } from 'expo-status-bar';
import { Fontisto } from "@expo/vector-icons";
import AsyncStorage from '@react-native-async-storage/async-storage';

import { theme } from './colors';


const STORAGE_KEY = "@toDos";

export default function App() {
  useEffect(() => {
    loadToDos().then();
  }, []);

  const [working, setWorking] = useState(true);
  const [text, setText] = useState("");
  const [toDos, setToDos] = useState({});
  const travel = () => setWorking(false);
  const work = () => setWorking(true);
  const onChangeText = (payload) => setText(payload);

  async function addTodo() {
    if (text === "") {
      return;
    }
    const newTodos = {
      ...toDos,
      [Date.now()]: {
        "text": text,
        "working": working
      }
    };
    setToDos(newTodos);
    await saveToDos(newTodos);
    console.log(toDos);
  }

  async function saveToDos(item) {
    try {
      await AsyncStorage.setItem(STORAGE_KEY, JSON.stringify(item));
    } catch (e) {
      console.log(`[ERROR] saveToDos : ${e}`);
    }
  }

  async function loadToDos() {
    const s = await AsyncStorage.getItem(STORAGE_KEY);
    setToDos(JSON.parse(s));
  }

  function deleteTodo(id) {
    const btnCancle = {text: "Cancle"};
    const btnOK = {
      text: "OK",
      style: "destructive", // only for IOS
      onPress: () => {
        // 직접적으로 state를 컨트롤하지 않고 ...을 통하여 새로운 object를 생성
        const newTodos = {...toDos};
        delete newTodos[id];
        setToDos(newTodos);
        saveToDos(newTodos).then();
      }
    };
    Alert.alert(
        "Delete To Do",
        "Are you sure delete this To Do?",
        [btnCancle, btnOK]
    );
  }

  return (
    <View style={styles.container}>
      <StatusBar style="auto" />
      <View style={styles.header}>
        <TouchableOpacity onPress={work}>
          <Text style={{...styles.headerBtn, color: working ? "white" : theme.grey}}>Work</Text>
        </TouchableOpacity>
        <TouchableOpacity onPress={travel}>
          <Text style={{...styles.headerBtn, color: !working ? "white" : theme.grey}}>Travel</Text>
        </TouchableOpacity>
      </View>
      <View>
        <TextInput
            keyboardType="default"
            returnKeyType="done"
            onChangeText={onChangeText}
            onSubmitEditing={addTodo}
            placeholder={working ? "Add a To Do!" : "Where do you want to go?"}
            style={styles.input}
        />
        <ScrollView>
          {Object.keys(toDos).map(key => (
              toDos[key].working === working ? (
                  <View key={key} style={styles.toDo}>
                    <Text style={styles.toDoText}>{toDos[key].text}</Text>
                    <TouchableOpacity onPress={() => deleteTodo(key)}>
                      <Fontisto name="trash" size={15} color={theme.grey} />
                    </TouchableOpacity>
                  </View>
              ) : null
          ))}
        </ScrollView>
      </View>
      <View></View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: 'black',
    paddingHorizontal: 20,
  },
  header: {
    flexDirection: "row",
    marginTop: 100,
    justifyContent: "space-between"
  },
  headerBtn: {
    fontSize: 38,
    fontWeight: "600",
  },
  input: {
    backgroundColor: "white",
    paddingHorizontal: 20,
    paddingVertical: 10,
    borderRadius: 30,
    marginTop: 20,
    marginBottom: 20,
    fontSize: 18,
  },
  toDo: {
    backgroundColor: theme.todoBg,
    marginBottom: 10,
    paddingVertical: 20,
    paddingHorizontal: 20,
    borderRadius: 15,
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "space-between",
  },
  toDoText: {
    color: "white",
    fontSize: 16,
  },
});
