package com.sp.fc.web.config;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.AccessDecisionManager;
import org.springframework.security.access.AccessDecisionVoter;
import org.springframework.security.access.expression.method.DefaultMethodSecurityExpressionHandler;
import org.springframework.security.access.expression.method.ExpressionBasedPreInvocationAdvice;
import org.springframework.security.access.expression.method.MethodSecurityExpressionHandler;
import org.springframework.security.access.expression.method.MethodSecurityExpressionOperations;
import org.springframework.security.access.intercept.RunAsManager;
import org.springframework.security.access.intercept.RunAsManagerImpl;
import org.springframework.security.access.method.MethodSecurityMetadataSource;
import org.springframework.security.access.prepost.PreInvocationAuthorizationAdviceVoter;
import org.springframework.security.access.vote.AffirmativeBased;
import org.springframework.security.access.vote.AuthenticatedVoter;
import org.springframework.security.access.vote.RoleVoter;
import org.springframework.security.config.annotation.method.configuration.EnableGlobalMethodSecurity;
import org.springframework.security.config.annotation.method.configuration.GlobalMethodSecurityConfiguration;
import org.springframework.security.core.Authentication;
import org.aopalliance.intercept.MethodInvocation;

@EnableGlobalMethodSecurity(prePostEnabled = true, securedEnabled = true)
public class MethodSecurityConfiguration extends GlobalMethodSecurityConfiguration {

    @Autowired
    private CustomPermissionEvaluator permissionEvaluator;

    @Override
    protected MethodSecurityMetadataSource customMethodSecurityMetadataSource() {
        return new CustomMetadataSource();
    }

    @Override
    protected RunAsManager runAsManager() {
        RunAsManagerImpl runAs = new RunAsManagerImpl();
        runAs.setKey("runas");
        return super.runAsManager();
    }

    @Override
    protected MethodSecurityExpressionHandler createExpressionHandler() {
        DefaultMethodSecurityExpressionHandler handler = new DefaultMethodSecurityExpressionHandler() {
            protected MethodSecurityExpressionOperations createSecurityExpressionRoot(Authentication authentication, MethodInvocation invocation) {
                CustomMethodSecurityExpressionRoot root = new CustomMethodSecurityExpressionRoot(authentication, invocation);
                root.setPermissionEvaluator(getPermissionEvaluator());
                return root;
            };
        };
        handler.setPermissionEvaluator(permissionEvaluator);
        return handler;
    }
    
    @Override
    protected AccessDecisionManager accessDecisionManager() {
        List<AccessDecisionVoter<?>> decisionVoters = new ArrayList<>();
        ExpressionBasedPreInvocationAdvice expressionAdvice = new ExpressionBasedPreInvocationAdvice();
		expressionAdvice.setExpressionHandler(getExpressionHandler());

        // 3?????? voter ??? ????????????
        decisionVoters.add(new PreInvocationAuthorizationAdviceVoter(expressionAdvice));
		decisionVoters.add(new RoleVoter());
		decisionVoters.add(new AuthenticatedVoter());
        decisionVoters.add(new CustomVoter()); // custom ??? voter ??????
        
        // ?????? ???????????? ??????
		return new AffirmativeBased(decisionVoters);
    }

}
