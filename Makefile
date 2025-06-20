# .SILENT is a special target to suppress the printing of all commands before they are executed.
# Or you can suppress the printing of specific commands by prefixing them with `@`.
.SILENT:

# Location to install binaries
LOCALBIN ?= $(shell pwd)/bin

# Versions
HELM_VERSION ?= v3.18.3
HELM_UNITTEST_VERSION ?= 0.8.2
HELM_DOCS_VERSION ?= v1.14.2
YQ_VERSION ?= v4.45.4

# Tool binaries
HELM ?= $(LOCALBIN)/helm-$(HELM_VERSION)
HELM_DOCS ?= $(LOCALBIN)/helm-docs-$(HELM_DOCS_VERSION)
YQ ?= $(LOCALBIN)/yq-$(YQ_VERSION)

##@ General

# .PHONY directive is used to declare phony targets, which are not real files but names for actions (e.g. clean, build, test, etc).
# When running `make help` will always display the help message, even if a file named `hello` exists.
# Best Practice: Always declare non-file targets as phony targets.
.PHONY: help
help: ## Display this help message.
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make \033[36m<target>\033[0m\n"} /^[a-zA-Z_0-9-]+:.*?##/ { printf "  \033[36m%-30s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

.PHONY: hello
hello: ## Hello, World!
	@echo "Hello, World!"

##@ Helm

.PHONY: helm-template
helm-template: $(HELM) ## Render Helm templates locally.
	$(HELM) template charts/playground

##@ Dependencies

$(LOCALBIN):
	mkdir -p $(LOCALBIN)

helm: $(HELM) ## Download helm locally if necessary, see https://github.com/helm/helm.
$(HELM): $(LOCALBIN)
	$(call go-install-tool,$(HELM),helm.sh/helm/v3/cmd/helm,$(HELM_VERSION))

.PHONY: helm-unittest-plugin
helm-unittest-plugin: helm ## Download helm unittest plugin locally if necessary, see https://github.com/helm-unittest/helm-unittest.
	if [ -z "$(shell $(HELM) plugin list | grep unittest)" ]; then \
		echo "Installing helm unittest plugin"; \
		$(HELM) plugin install https://github.com/helm-unittest/helm-unittest.git --version $(HELM_UNITTEST_VERSION); \
	fi

helm-docs-plugin: $(HELM_DOCS) ## Download helm-docs locally if necessary, see https://github.com/norwoodj/helm-docs.
$(HELM_DOCS): $(LOCALBIN)
	$(call go-install-tool,$(HELM_DOCS),github.com/norwoodj/helm-docs/cmd/helm-docs,$(HELM_DOCS_VERSION))

yq: $(YQ) ## Download yq locally if necessary, see https://github.com/mikefarah/yq.
$(YQ): $(LOCALBIN)
	$(call go-install-tool,$(YQ),github.com/mikefarah/yq/v4,$(YQ_VERSION))

# Use `define ... endef` to declare reusable code blocks (like functions).

# go-install-tool will 'go install' any package with custom target and name of binary, if it doesn't exist
# $1 - target path with name of binary (ideally with version)
# $2 - package url which can be installed
# $3 - specific version of package
define go-install-tool
@[ -f $(1) ] || { \
set -e; \
package=$(2)@$(3) ;\
echo "Downloading $${package}" ;\
GOBIN=$(LOCALBIN) go install $${package} ;\
mv "$$(echo "$(1)" | sed "s/-$(3)$$//")" $(1) ;\
}
endef
