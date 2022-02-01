package com.sp.fc.web.controller;

import java.util.List;

import com.sp.fc.web.config.CustomSecurityTag;
import com.sp.fc.web.service.Paper;
import com.sp.fc.web.service.PaperService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.security.access.prepost.PostAuthorize;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.security.core.userdetails.User;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;



@RestController
@RequestMapping("/paper")
public class PaperController {
    
    @Autowired
    private PaperService paperService;

    // @PreAuthorize("isStudent()")
    // @PostFilter("filterObject.state != T(com.sp.fc.web.service.Paper.State).PREPARE") <- 실용성이 부족하기때문에 Method에 설정
    // @PostFilter("notPrepareState(filterObject)")
    @GetMapping("/mypapers")
    public List<Paper> myPapers(@AuthenticationPrincipal User user) {
        return paperService.getMyPapers(user.getUsername());
    }

    @Secured({"ROLE_USER", "RUN_AS_PRIMARY"})
    @GetMapping("/allpapers")
    public List<Paper> allPapers(@AuthenticationPrincipal User user) {
        return paperService.getAllPapers();
    }

    // @PreAuthorize("hasPermission(#paperId, 'paper', 'read')")
    @PostAuthorize("returnObject.studentIds.contains(#user.username)")
    @GetMapping("/get/{paperId}")
    public Paper getPaper(@AuthenticationPrincipal User user, @PathVariable Long paperId) {
        return paperService.getPaper(paperId);
    }

    // @Secured({"SCHOOL_PRIMARY"})
    @CustomSecurityTag("SCHOOL_PRIMARY")
    @GetMapping("/getPapersByPrimary")
    public List<Paper> getPapersByPrimary(@AuthenticationPrincipal User user) {
        return paperService.getAllPapers();
    }

}
