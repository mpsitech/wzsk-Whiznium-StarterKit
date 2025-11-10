<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="3">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzskVExpstate=='regd'"
		>
			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg1}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf2"
				:label="tag.Cpt2"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.Chk3"
				v-on:change='updateEng(["contiac"])'
				:label="tag.Cpt3"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf4"
				:label="tag.Cpt4"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf5"
				:label="tag.Cpt5"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf6"
				:label="tag.Cpt6"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg101}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf102"
				:label="tag.Cpt102"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.Chk103"
				v-on:change='updateEng(["contiac"])'
				:label="tag.Cpt103"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf104"
				:label="tag.Cpt104"
			/>

			<v-divider v-if="statshr.Sep2Avail"/>

			<h3
				v-if="statshr.Hdg201Avail"
				class="text-5 my-1"
			>
				{{tag.Hdg201}}
			</h3>

			<v-text-field
				v-if="statshr.Txf202Avail"
				class="my-1"
				v-model="contiac.Txf202"
				:label="tag.Cpt202"
			/>

			<v-text-field
				v-if="statshr.Txf203Avail"
				class="my-1"
				v-model="contiac.Txf203"
				:label="tag.Cpt203"
			/>

			<v-checkbox
				v-if="statshr.Chk204Avail"
				class="my-1"
				v-model="contiac.Chk204"
				v-on:change='updateEng(["contiac"])'
				:label="tag.Cpt204"
			/>

			<v-checkbox
				v-if="statshr.Chk205Avail"
				class="my-1"
				v-model="contiac.Chk205"
				v-on:change='updateEng(["contiac"])'
				:label="tag.Cpt205"
			/>

			<v-checkbox
				v-if="statshr.Chk206Avail"
				class="my-1"
				v-model="contiac.Chk206"
				v-on:change='updateEng(["contiac"])'
				:label="tag.Cpt206"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg301}}
			</h3>

			<v-select
				class="my-1"
				v-model="contapp.fiFPup302"
				return-object
				:items="feedFPup302"
				item-value="num"
				item-text="tit1"
				:label="tag.Cpt302"
				v-on:change="handleFiChange('numFPup302', contapp.fiFPup302)"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf303"
				:label="tag.Cpt303"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf304"
				:label="tag.Cpt304"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf305"
				:label="tag.Cpt305"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf306"
				:label="tag.Cpt306"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf307"
				:label="tag.Cpt307"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf308"
				:label="tag.Cpt308"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg401}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf402"
				:label="tag.Cpt402"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf403"
				:label="tag.Cpt403"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf404"
				:label="tag.Cpt404"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf405"
				:label="tag.Cpt405"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf406"
				:label="tag.Cpt406"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf407"
				:label="tag.Cpt407"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg501}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf502"
				:label="tag.Cpt502"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf503"
				:label="tag.Cpt503"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg601}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf602"
				:label="tag.Cpt602"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf603"
				:label="tag.Cpt603"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf604"
				:label="tag.Cpt604"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf605"
				:label="tag.Cpt605"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf606"
				:label="tag.Cpt606"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskPrfDaemon',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskPrfDaemon.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskPrfDaemonDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleFiChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskPrfDaemon"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskPrfDaemonData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskPrfDaemonData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskPrfDaemon) this.contiac = dpcheng.ContIacWzskPrfDaemon;
				if (dpcheng.FeedFPup302) this.feedFPup302 = dpcheng.FeedFPup302;
				if (dpcheng.StatShrWzskPrfDaemon) this.statshr = dpcheng.StatShrWzskPrfDaemon;
				if (dpcheng.TagWzskPrfDaemon) {
					Wzsk.unescapeBlock(dpcheng.TagWzskPrfDaemon);
					this.tag = dpcheng.TagWzskPrfDaemon;
				}
				if (dpcheng.ContIacWzskPrfDaemon) {
					for (let i = 0; i < this.feedFPup302.length; i++)
						if (this.feedFPup302[i].num == this.contiac.numFPup302) {
							this.contapp.fiFPup302 = this.feedFPup302[i];
							break;
						}
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskPrfDaemonData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskPrfDaemonData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			feedFPup302: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPup302: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
