package spring.hellospring.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {
    
    @GetMapping("hello")
    public String hello(Model model) {
        model.addAttribute("data", "hello!");
        return "hello";
    }

    @GetMapping("hello-mvc")
    public String helloMvc(@RequestParam("name") String name, Model model) {
        model.addAttribute("name", name);
        return "hello-template";
    }

    // 쓸일 잘없음
    @GetMapping("hello-string")
    @ResponseBody // http 의 body 부분에 return 부분을 직접 넣어주겠다
    public String helloString(@RequestParam("name") String name) {
        return "hello " + name;
    }

    
    // JSON 형태로 보여지게됨 {"name": "spring!!!"}
    // 객체를 return 하게되면 JSON 으로 http response 된다.
    @GetMapping("hello-api")
    @ResponseBody
    public Hello helloApi(@RequestParam("name") String name) {
        Hello hello = new Hello();
        hello.setName(name);
        return hello;
    }



    static class Hello {
        private String name;
        
        public String getName() {
            return name;
        }
        public void setName(String name) {
            this.name = name;
        }
    }
    
} // end of class
