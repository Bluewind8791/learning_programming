import {
  Alert,
  ScrollView,
  StyleSheet,
  Text,
  TextInput,
  TouchableOpacity,
  View
} from 'react-native';
import {useEffect, useRef, useState} from "react";

import { StatusBar } from 'expo-status-bar';
import { Fontisto } from "@expo/vector-icons";
import { Feather } from '@expo/vector-icons';
import AsyncStorage from '@react-native-async-storage/async-storage';

import { theme } from './colors';


const STORAGE_KEY = "@toDos";
const STORAGE_TAB_KEY = "@tab";


export default function App() {

  const textInput = useRef();

  useEffect(() => {
    loadToDos().then();
    loadTabInfo();
  }, []);

  const [working, setWorking] = useState(true);
  const [text, setText] = useState("");
  const [toDos, setToDos] = useState({});

  const travel = () => switchTab(false);
  const work = () => switchTab(true);
  function switchTab(isWork) {
    setWorking(isWork);
    AsyncStorage.setItem(STORAGE_TAB_KEY, isWork ? "true" : "false").then();
  }
  function loadTabInfo() {
    AsyncStorage.getItem(STORAGE_TAB_KEY)
        .then(r => r === "true" ? setWorking(true) : setWorking(false))
        .catch(e => console.log(`[ERROR] loadTabInfo : ${e}`))
    ;
  }

  const onChangeText = (payload) => setText(payload);
  async function addTodo() {
    if (text === "") {
      return;
    }
    const newTodos = {
      ...toDos,
      [Date.now()]: {
        "text": text,
        "working": working,
        "isDone" : false,
        "isEditing" : false,
      }
    };
    setToDos(newTodos);
    await saveToDos(newTodos);
    // clear text input
    textInput.current.clear();
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

  function switchDone(id) {
    const newTodos = {...toDos};
    const isDone = newTodos[id].isDone;
    newTodos[id].isDone = !isDone;
    setToDos(newTodos);
    saveToDos(newTodos).then();
    console.log(newTodos);
  }

  // 수정 기능
  const [editText, setEditText] = useState("");

  /**
   * 텍스트 수정
   * @param id
   * @param isEditing true: 수정 진입 / false: 수정 취소
   */
  function setIsEditing(id, isEditing) {
    // touch edit box then make new input box
    const newTodos = {...toDos};
    newTodos[id].isEditing = isEditing;
    setToDos(newTodos);
    saveToDos(newTodos).then();
    console.log(newTodos);
  }

  function saveEditText(id) {
    const newTodos = {...toDos};
    newTodos[id].isEditing = false;

    if (editText) {
      newTodos[id].text = editText;
    }

    setEditText("");
    setToDos(newTodos);
    saveToDos(newTodos).then();
    console.log(newTodos);
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
      <TextInput
          ref={textInput}
          keyboardType="default"
          returnKeyType="done"
          onChangeText={onChangeText}
          onSubmitEditing={addTodo}
          placeholder={working ? "Add a To Do!" : "Where do you want to go?"}
          style={styles.input}
      />
      <ScrollView>
        {toDos ? (
            Object.keys(toDos).map(key => (
                // 활성중인 탭에 따른 리스트 표시
                toDos[key].working === working ? (
                  toDos[key].isEditing ? (
                      <View key={key} style={{...styles.toDo, backgroundColor: "white"}}>
                        <TextInput
                            keyboardType="default"
                            returnKeyType="done"
                            onChangeText={(payload) => setEditText(payload)}
                            onSubmitEditing={() => saveEditText(key)}
                            onBlur={() => setIsEditing(key, false)}
                            placeholder={toDos[key].text}
                            multiline={false}
                            style={styles.editInput}
                        />
                        <TouchableOpacity onPress={() => saveEditText(key)} style={styles.editIcon} >
                          <Feather name="check" size={15} color="black" />
                        </TouchableOpacity>
                      </View>
                  ) : (
                      <View key={key} style={styles.toDo}>
                        <View style={styles.toDoLeftBox}>
                          <TouchableOpacity onPress={() => switchDone(key)}>
                            {toDos[key].isDone ? (
                                <Fontisto name={"checkbox-active"} size={15} color="grey"/>
                            ) : (
                                <Fontisto name={"checkbox-passive"} size={15} color={theme.grey}/>
                            )}
                          </TouchableOpacity>
                          <Text
                              onPress={() => setIsEditing(key, true)}
                              style={{
                                ...styles.toDoText,
                                color: toDos[key].isDone ? theme.grey : "white",
                                textDecorationLine: toDos[key].isDone ? "line-through" : "none",
                              }}
                          >
                            {toDos[key].text}
                          </Text>
                        </View>
                        <View style={styles.toDoIconBox}>
                          <TouchableOpacity onPress={() => setIsEditing(key, true)}>
                            <Feather name="edit" size={15} color={theme.grey}/>
                          </TouchableOpacity>
                          <TouchableOpacity onPress={() => deleteTodo(key)}>
                            <Fontisto name="trash" size={15} color={theme.grey}/>
                          </TouchableOpacity>
                        </View>
                      </View>
                  )
                ) : null) // end of is working
            ) // end of map
        ) : null}
      </ScrollView>
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
    fontSize: 18,
    marginTop: 20,
    marginBottom: 20,
  },
  toDo: {
    flex: 1,
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
    fontSize: 16,
    marginLeft: 15,
  },
  toDoLeftBox: {
    flex: 6,
    flexDirection: "row",
    alignItems: "center"
  },
  toDoIconBox: {
    flex: 1,
    flexDirection: "row",
    justifyContent: "space-between",
  },
  editInput: {
    flex: 7,
    marginVertical: -4,
    paddingHorizontal: 10,
    fontSize: 18,
    borderRadius: 15,
  },
  editIcon: {
    flex: 1,
    alignItems: "center",
  },
});
