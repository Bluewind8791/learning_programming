package com.sp.fc.web.controller;


import com.sp.fc.web.config.CustomSecurityTag;
import com.sp.fc.web.service.Paper;
import com.sp.fc.web.service.PaperService;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.security.access.prepost.PostAuthorize;
import org.springframework.security.access.prepost.PostFilter;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.security.core.userdetails.User;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/paper")
@RequiredArgsConstructor
public class PaperController {

    private final PaperService paperService;

//    @PreAuthorize("isStudent()")
    @PostFilter("notPrepareState(filterObject) && filterObject.studentIds.contains(#user.username)")
    @GetMapping("/mypapers")
    public List<Paper> myPapers(@AuthenticationPrincipal User user){
        return paperService.getMyPapers(user.getUsername());
    }

//    @PreAuthorize("hasPermission(#paperId, 'paper', 'read')")
    @PostAuthorize("returnObject.studentIds.contains(principal.username)")
    @GetMapping("/get/{paperId}")
    public Paper getPaper(@AuthenticationPrincipal User user, @PathVariable Long paperId){
        return paperService.getPaper(paperId);
    }

    @Secured({"ROLE_USER", "RUN_AS_PRIMARY"})
    @GetMapping("/allpapers")
    public List<Paper> allpapers(@AuthenticationPrincipal User user){
        return paperService.getAllPapers();
    }

    @CustomSecurityTag("SCHOOL_PRIMARY")
    @GetMapping("/getPapersByPrimary")
    public List<Paper> getPapersByPrimary(@AuthenticationPrincipal User user){
        return paperService.getAllPapers();
    }

}
