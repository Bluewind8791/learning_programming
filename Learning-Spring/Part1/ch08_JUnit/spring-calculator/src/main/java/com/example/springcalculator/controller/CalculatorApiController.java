package com.example.springcalculator.controller;

import com.example.springcalculator.component.Calculator;
import com.example.springcalculator.dto.Req;
import com.example.springcalculator.dto.Res;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import lombok.RequiredArgsConstructor;

@RestController
@RequestMapping("/api")
@RequiredArgsConstructor
public class CalculatorApiController {
    
    private final Calculator calculator;


    @GetMapping("/sum")
    public int sum(@RequestParam int x, @RequestParam int y) {
        return calculator.sum(x, y);
    }

    // @GetMapping("/minus")
    // public int minus(@RequestParam int x, @RequestParam int y) {
    //     return calculator.minus(x, y);
    // }


    // Post mapping
    // @PostMapping("/sum")
    // public Res sum(@RequestBody Req req) {

    //     int result = calculator.sum(req.getX(), req.getY());

    //     Res res = new Res();
    //     res.setResult(result);
    //     res.setResponse(new Res.Body());

    //     return res;
    // }

    @PostMapping("/minus")
    public Res minus(@RequestBody Req req) {

        int result = calculator.minus(req.getX(), req.getY());

        Res res = new Res();
        res.setResult(result);
        res.setResponse(new Res.Body());

        return res;
    }
}
