package com.cortez.samples.javaee7angular.rest;

import com.cortez.samples.javaee7angular.data.Issue;
import com.cortez.samples.javaee7angular.pagination.PaginatedListWrapper;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;
import javax.ws.rs.*;
import javax.ws.rs.core.Application;
import javax.ws.rs.core.MediaType;
import java.util.List;

/**
 * REST Service to expose the data to display in the UI grid.
 *
 * @author Roberto Cortez
 */
@Stateless
@ApplicationPath("/resources")
@Path("issues")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class IssueResource extends Application {
    
    
    @PersistenceContext
    private EntityManager entityManager;

    private Integer countIssues() {
        Query query = entityManager.createQuery("SELECT COUNT(p.id) FROM Issue p");
        return ((Long) query.getSingleResult()).intValue();
    }

    @SuppressWarnings("unchecked")
    private List<Issue> findIssue(int startPosition, int maxResults, String sortFields, String sortDirections) {
        Query query =
                entityManager.createQuery("SELECT p FROM Issue p ORDER BY p." + sortFields + " " + sortDirections);
        query.setFirstResult(startPosition);
        query.setMaxResults(maxResults);
        return query.getResultList();
    }

    private PaginatedListWrapper findIssues(PaginatedListWrapper wrapper) {
        wrapper.setTotalResults(countIssues());
        int start = (wrapper.getCurrentPage() - 1) * wrapper.getPageSize();
        wrapper.setList(findIssue(start,
                                    wrapper.getPageSize(),
                                    wrapper.getSortFields(),
                                    wrapper.getSortDirections()));
        return wrapper;
    }

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public PaginatedListWrapper listIssues(@DefaultValue("1")
                                            @QueryParam("page")
                                            Integer page,
                                            @DefaultValue("id")
                                            @QueryParam("sortFields")
                                            String sortFields,
                                            @DefaultValue("asc")
                                            @QueryParam("sortDirections")
                                            String sortDirections) {
        PaginatedListWrapper paginatedListWrapper = new PaginatedListWrapper();
        paginatedListWrapper.setCurrentPage(page);
        paginatedListWrapper.setSortFields(sortFields);
        paginatedListWrapper.setSortDirections(sortDirections);
        paginatedListWrapper.setPageSize(10);
        return findIssues(paginatedListWrapper);
    }

    @GET
    @Path("{id}")
    public Issue getIssue(@PathParam("id") Long id) {
        return entityManager.find(Issue.class, id);
    }

    @POST
    public Issue saveIssue(Issue issue) {
        if (issue.getId() == null) {
            Issue issueToSave = new Issue();
            issueToSave.setIssueNum(issue.getIssueNum());
            issueToSave.setP1Rate(issue.getP1Rate());
            issueToSave.setP2Rate(issue.getP2Rate());
            entityManager.persist(issue);
        } else {
            Issue issueToUpdate = getIssue(issue.getId());
            issueToUpdate.setIssueNum(issue.getIssueNum());
            issueToUpdate.setP1Rate(issue.getP1Rate());
            issueToUpdate.setP2Rate(issue.getP2Rate());
            issue = entityManager.merge(issueToUpdate);
        }

        return issue;
    }

    @DELETE
    @Path("{id}")
    public void deleteIssue(@PathParam("id") Long id) {
        entityManager.remove(getIssue(id));
    }
}
