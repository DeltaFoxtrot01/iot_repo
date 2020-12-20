package com.example.demo;

import java.util.ArrayList;
import java.util.List;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class Controller {
  

  @GetMapping("/api")
  public List<String> getList(){
    List<String> res = new ArrayList<>();
    res.add("something");
    res.add("nice");
    return res;
  }

  @PostMapping("/api")
  public Dto getDto(@RequestBody Dto arg){
    String aux = arg.getSomething();
    Dto res = new Dto();
    res.setSomething(aux + " response");
    return res;    
  }

}
